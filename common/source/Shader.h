//
//  Shader.m
//  opengl-study
//
//  Created by lijinhu on 3/28/16.
//  Copyright © 2016 李金虎. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL2.h>

const char *readFileFromBundle(NSString *fileName, NSString *fileExtension);

// 初始化顶点着色器和片段颜色器
GLuint initShaders(NSString *vertexShaderName, NSString *fragmentShaderName, NSString *ext)
{
    // create vertex shader
    const GLchar *vertexShaderSource = readFileFromBundle(vertexShaderName, ext);
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    }
    
    // create fragment shader
    const GLchar *fragmentShaderSource = readFileFromBundle(fragmentShaderName, ext);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    }
    
    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    return shaderProgram;
}

// 读取文件
const char *readFileFromBundle(NSString *fileName, NSString *fileExt)
{
    NSString *filePath = [[NSBundle mainBundle] pathForResource:fileName ofType:fileExt];
    NSString *testString = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil];
    return testString.UTF8String;
}