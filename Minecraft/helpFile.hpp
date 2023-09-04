#ifndef HELPFILE_H
#define HELPFILE_H

#include <SFML/OpenGL.hpp>
#include <GL/glu.h>
#define GL_CLAMP_TO_EDGE 0x812F

const float PI =3.141592653; 
bool mass[1000][1000][1000];
float size = 20.f;

GLuint LoadTexture(sf::String name)
{
	    sf::Image image;
        if (!image.loadFromFile(name))
            return EXIT_FAILURE;

		image.flipVertically(); 

		GLuint texture=0;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);  

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		return texture;
}


void createBox(GLuint skybox[],float size)
{
	    glBindTexture(GL_TEXTURE_2D, skybox[0]);
	    glBegin(GL_QUADS);
		    //front
            glTexCoord2f(0, 0);   glVertex3f(-size, -size, -size);
            glTexCoord2f(1, 0);   glVertex3f(size,  -size, -size);
            glTexCoord2f(1, 1);   glVertex3f( size,  size, -size);
            glTexCoord2f(0, 1);   glVertex3f( -size, size, -size);
        glEnd();
		
	    glBindTexture(GL_TEXTURE_2D, skybox[1]);
	    glBegin(GL_QUADS);
			//back
            glTexCoord2f(0, 0); glVertex3f(size, -size, size);
            glTexCoord2f(1, 0); glVertex3f(-size,  -size, size);
            glTexCoord2f(1, 1); glVertex3f( -size,  size, size);
            glTexCoord2f(0, 1); glVertex3f( size, size, size);
        glEnd();

		glBindTexture(GL_TEXTURE_2D, skybox[2]);
	    glBegin(GL_QUADS);
			//left
            glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
            glTexCoord2f(1, 0); glVertex3f(-size, -size, -size);
            glTexCoord2f(1, 1); glVertex3f(-size,  size, -size);
            glTexCoord2f(0, 1); glVertex3f(-size,  size,  size);
        glEnd();

		glBindTexture(GL_TEXTURE_2D, skybox[3]);
	    glBegin(GL_QUADS);
			//right
            glTexCoord2f(0, 0); glVertex3f(size, -size, -size);
            glTexCoord2f(1, 0); glVertex3f(size,  -size, size);
            glTexCoord2f(1, 1); glVertex3f(size,  size,  size);
            glTexCoord2f(0, 1); glVertex3f(size, size,  -size);
        glEnd();

		glBindTexture(GL_TEXTURE_2D, skybox[4]);
	    glBegin(GL_QUADS);
			//bottom
            glTexCoord2f(0, 0); glVertex3f(-size, -size,  size);
            glTexCoord2f(1, 0); glVertex3f(size, -size, size);
            glTexCoord2f(1, 1); glVertex3f( size, -size, -size);
            glTexCoord2f(0, 1); glVertex3f( -size, -size,  -size);
        glEnd();

	    glBindTexture(GL_TEXTURE_2D, skybox[5]);
	    glBegin(GL_QUADS);
			//top  		
            glTexCoord2f(0, 0); glVertex3f(-size, size,  -size);
            glTexCoord2f(1, 0); glVertex3f(size, size, -size);
            glTexCoord2f(1, 1); glVertex3f( size, size, size);
            glTexCoord2f(0, 1); glVertex3f( -size, size,  size);	     
        glEnd();
}


bool check(int x, int y, int z)
{
   if ((x<0) || (x>=1000) || 
	   (y<0) || (y>=1000) || 
	   (z<0) || (z>=1000)) return false;
  
   return mass[x][y][z];
}



#endif HELPFILE_H