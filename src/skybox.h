#pragma once
#include <vector>
#include <string>
#include "Textures.h"


struct CubeMap {
	unsigned int textureID;
	Texture texture;

	//CubeMap(std::vector<std::string> faces);
	CubeMap(std::vector<std::string> faces) :texture(GL_TEXTURE_CUBE_MAP) {
		texture.bind();
		textureID = texture.textureID;

		for (int i = 0; i < faces.size(); i++) {
			texture.loadTexture(faces[i], GL_TEXTURE_CUBE_MAP_POSITIVE_X + i);
		}
	}

	void bind() const {
		glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	}
};