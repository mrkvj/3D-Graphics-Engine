
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>

char* readFile(const char* filePath) {

    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("ERROR: File path %s could not be opened.", filePath);
		return 0;
    }

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* content = (char*) malloc(length + 1);
	if (content == NULL) {
		fclose(file);
		printf("Memory allocation failed\n");
		exit(1);
	}

	fread(content, 1, length, file);
	content[length] = '\0';
	fclose(file);

	return content;
}

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file (C version)
    char* VertexShaderCode = readFile(vertex_file_path);
	if (VertexShaderCode == NULL) {
		exit(1);
	}

	// Read the Fragment Shader code from the file (C version)
	char* FragmentShaderCode = readFile(fragment_file_path);
	if (FragmentShaderCode == NULL) {
		free(VertexShaderCode);
		exit(1);
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader: %s\n", vertex_file_path);
	glShaderSource(VertexShaderID, 1, (const GLchar**)&VertexShaderCode, NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader (C version)
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0){
		char* VertexShaderErrorMessage = (char*)malloc(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, VertexShaderErrorMessage);
		printf("Vertex Shader compilation error: %s\n", VertexShaderErrorMessage);
		free(VertexShaderErrorMessage);
		free(VertexShaderCode);
		free(FragmentShaderCode);
		exit(1);
	}

	// Compile Fragment Shader
	printf("Compiling shader: %s\n", fragment_file_path);
	glShaderSource(FragmentShaderID, 1, (const GLchar**)&FragmentShaderCode, NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader (C version)
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0){
		char* FragmentShaderErrorMessage = (char*)malloc(InfoLogLength + 1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, FragmentShaderErrorMessage);
		printf("Fragment Shader compilation error: %s\n", FragmentShaderErrorMessage);
		free(FragmentShaderErrorMessage);
		free(VertexShaderCode);
		free(FragmentShaderCode);
		exit(1);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0){
		char* ProgramErrorMessage = (char*)malloc(InfoLogLength);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, ProgramErrorMessage);
		printf("Program linking error: %s\n", ProgramErrorMessage);
		free(ProgramErrorMessage);
		free(VertexShaderCode);
		free(FragmentShaderCode);
		exit(1);
	}
	
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	free(VertexShaderCode);
	free(FragmentShaderCode);

	return ProgramID;
}
