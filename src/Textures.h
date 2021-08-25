#pragma once

#include <glad/glad.h>
#include "stb_image.h"
#include <string>
#include <iostream>

struct Texture {
	unsigned int textureID;
	unsigned char* data;
	unsigned int target;
	std::string type;
	std::string path;
	GLenum format;

	Texture(const unsigned int _target = GL_TEXTURE_2D);

	Texture(std::string path, std::string type);

	void loadTexture(std::string path, GLenum texTarget = GL_TEXTURE_2D);

	Texture(std::string path, const unsigned int _target = GL_TEXTURE_2D);

	void bind(const int slot = 0) const;

	void unbind() const;

	std::string getType() const {
		return type;
	}

	~Texture();
};