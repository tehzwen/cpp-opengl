#include "shader.h"
#define SHADER_LOCATION "./src/shaders/"

using namespace std;

Shader::Shader(string fileName)
{
    program = glCreateProgram();
    vertexSource = loadShaderFile(fileName + ".vert.glsl");
    fragSource = loadShaderFile(fileName + ".frag.glsl");
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char *fragmentShaderSource[1] = {fragSource.c_str()};
    glShaderSource(fragmentShader, 1, fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    const char *vertexShaderSource[1] = {vertexSource.c_str()};
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    checkShaderStatus();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    cout << "HERE!" << endl;
    cout << program << endl;
}

void Shader::checkShaderStatus()
{
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        glDeleteShader(vertexShader);
    }

    char fragInfoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, fragInfoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << fragInfoLog << std::endl;
        glDeleteShader(fragmentShader);
    }
}

string Shader::loadShaderFile(string name)
{
    string filePath = SHADER_LOCATION;
    filePath += name;
    string contents;
    fstream newfile;
    newfile.open(filePath, ios::in); //open a file to perform read operation using file object
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(newfile, tp))
        { //read data from file object and put it into string.
            contents += tp;
            contents += "\n";
        }
        newfile.close(); //close the file object.
    }

    return contents;
}
