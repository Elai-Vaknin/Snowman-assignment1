#include <iostream>
#include <stdexcept>
#include "snowman.hpp"
#include <sstream>

using namespace std;

#define UPPER_ARM 2

stringstream stream;

enum { 
	Base = 0,
	Torso,
	RightArm,
	LeftArm,
	RightEye,
	LeftEye,
	Nose,
	Hat,
	Parts
};

void drawPart(int p, int value) {
	switch(p) {
		case Hat: {
			switch(value) {
				case 1: stream << " _===_"; break;
				case 2: stream << "  ___ " << endl << " ....."; break;
				case 3: stream << "   _  " << endl << "  /_\\ "; break;
				case 4: stream << "  ___ " << endl << " (_*_)"; break;
			}
			
			break;
		}
		
		case Nose: {  
			switch(value) {
				case 1: stream << ","; break;
				case 2: stream << "."; break;
				case 3: stream << "_"; break;
				case 4: stream << " "; break;
			}
			
			break; 
		}
		case LeftEye:
		case RightEye: {  
			switch(value) {
				case 1: stream << "."; break;
				case 2: stream << "o"; break;
				case 3: stream << "O"; break;
				case 4: stream << "-"; break;
			}
			
			break; 
		}
		
		case LeftArm: {  
			switch(value) {
				case 1: stream << "<"; break;
				case 2: stream << "\\"; break;
				case 3: stream << "/"; break;
				case 4: stream << " "; break;
			}
			
			break; 
		}
		case RightArm: {  
			switch(value) {
				case 1: stream << ">"; break;
				case 2: stream << "/"; break;
				case 3: stream << "\\"; break;
				case 4: stream << " "; break;
			}
			
			break; 
		}
		case Torso: {  
			switch(value) {
				case 1: stream << " : "; break;
				case 2: stream << "] ["; break;
				case 3: stream << "> <"; break;
				case 4: stream << "   "; break;
			}
			
			break; 
		}
		case Base: {  
			switch(value) {
				case 1: stream << " : "; break;
				case 2: stream << "\" \""; break;
				case 3: stream << "___"; break;
				case 4: stream << "   "; break;
			}
			
			break; 
		}
	}
}

void draw(int v[Parts]) { 
	drawPart(Hat, v[Hat]);
	
	stream << endl;
	
	
	if(v[LeftArm] == UPPER_ARM)
		drawPart(LeftArm, v[LeftArm]);
	else
		stream << " ";
		
	stream << "(";
	
	drawPart(LeftEye, v[LeftEye]);
	drawPart(Nose, v[Nose]);
	drawPart(RightEye, v[RightEye]);
	
	stream << ")";
	

	
	if(v[RightArm] == UPPER_ARM)
		drawPart(RightArm, v[RightArm]);
		
	stream << endl;
	
	if(v[LeftArm] != UPPER_ARM)
		drawPart(LeftArm, v[LeftArm]);
	else
		stream << " ";
		
	stream << "(";
	
	drawPart(Torso, v[Torso]);
	
	stream << ")";
	
	if(v[RightArm] != UPPER_ARM)
		drawPart(RightArm, v[RightArm]);
		
	stream << endl;
	

	
	stream << " (";
	
	drawPart(Base, v[Base]);
	
	stream << ")" << endl;
}

namespace ariel{
	string snowman(int code) {
		int v[Parts];
			
		stream.str("");
		stream.clear();
		
		for( int i = 0; i < Parts; i++ ) {
			v[i] = code % 10;
				
			if(v[i] > 4 || v[i] < 1)
				throw std::out_of_range("Each digit has to be between 1 to 4");
				
			if(code <= 0)
				throw std::length_error("String have to be 8 characters long");
					
			code /= 10;
		}
			
		if(code > 0)
			throw std::length_error("String have to be 8 characters long");
			
		draw(v);
			
		return stream.str();
	}
}

