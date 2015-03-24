/*
 * Copyright (c) 2014 Antoine Rousseau <antoine@metalu.net>
 * BSD Simplified License, see the file "LICENSE.txt" in this distribution.
 * See https://github.com/Ant1r/ofxPof for documentation and updates.
 */
#pragma once

#include "pofBase.h"

class pofIm;

class pofImage: public pofBase {
	public:
		pofImage(t_class *Class, t_symbol *f=NULL, float w=0, float h=0, float xa=0, float ya=0, float sx=0, float sy=0, float sw=0, float sh=0):pofBase(Class),file(NULL), displayedFile(NULL), width(w), height(h), xanchor(xa), yanchor(ya), subx(sx), suby(sy), subwidth(sw), subheight(sh), image(NULL),reservedChanged(false), monitor(false) {
			m_out2 = outlet_new(&(pdobj->x_obj), 0);
		}
		//virtual ~pofImage() { }

		void Update(); // not real "update()" !
		virtual void draw();
		
		void set(t_symbol *f);
		
		void reserve(t_symbol *f);
		void unreserve(t_symbol *f);
		void unreserveAll();
		
		static void setup(void);
		
		t_symbol *file, *displayedFile;
		
		float width, height;	
		float imWidth, imHeight;	
		float xanchor, yanchor;
		float subx, suby;
		float subwidth, subheight;
		t_canvas *pdcanvas;
		pofIm *image;
		t_outlet *m_out2;
		
		std::list<pofIm*> reserved;
		bool reservedChanged;
		
		unsigned int loaderLen; // number of images waiting to be loaded.
		unsigned int loaderLenHTTP; // number of online images waiting to be loaded.
		unsigned int imgLen; // total number of (pre)loaded images.
		bool monitor;
};


