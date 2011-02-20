#pragma once

#include "model.h"

using namespace std;


class PrimitiveModel : public Model {
	
	public:
		PrimitiveModel(int type);
		~PrimitiveModel(void);
		
		vector<Patch*>* getPatches(double area = 0); // vraci pole plosek modelu (rozdelenych na max. obsah "area")

		const enum {
			ROOM,
			CUBE,
			BLOCK
		};

	private:		
		int type;	// typ modelu - hodnota z enumu; pouze docasne
		static const float room[];
		static const float cube[];
		static const float block[];
		static const int roomIndices[];
		static const int cubeIndices[];
		static const int blockIndices[];
};
