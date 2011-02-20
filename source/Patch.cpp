#include "Patch.h"


Patch::Patch(Vector3f vec1, Vector3f vec2, Vector3f vec3, Vector3f vec4) {
	Patch::vec1 = vec1;
	Patch::vec2 = vec2;
	Patch::vec3 = vec3;
	Patch::vec4 = vec4;
}


Patch::~Patch(void) {
}



/**
 * Vraci dynamicky alokovany vektor plosek, maji polovicni
 * delku hrany. Pokud je obsah plosky mensi nebo roven zadanemu,
 * vraci NULL
 */
vector<Patch*>* Patch::divide(double area) {	
		
	/*
		vec4	vec3			D	CD	C
						-->		DA	E	BC
		vec1	vec2			A	AB	B
	*/

	//cout << "====================" << endl;
	//cout << "Deleni do plochy " << area << endl;

	Vector3f A = vec1;
	Vector3f B = vec2;
	Vector3f C = vec3;
	Vector3f D = vec4;

	// uhlopricky
	Vector3f u1 = A - C;
	Vector3f u2 = B - D;

	//cout << "u1: " << u1.x << " ; " << u1.y << " ; " << u1.z << endl;
	//cout << "u2: " << u2.x << " ; " << u2.y << " ; " << u2.z << endl;

	// uhel mezi uhloprickami
	double phi = acos( u1.f_Dot(u2) / (u1.f_Length() * u2.f_Length()) );
	//cout << "phi: " << phi << endl;

	// obsah patche
	double S = 0.5f * u1.f_Length() * u2.f_Length() * sin(phi);
	//cout << "S: " << S << endl;

	if (S <= area)
		return NULL;	

	// spocitat nove ctvrtinove patche
	Vector3f AB = (A + B) / 2;
	Vector3f BC = (B + C) / 2;
	Vector3f CD = (C + D) / 2;
	Vector3f DA = (D + A) / 2;
	Vector3f E  = (A + C) / 2;

	vector<Patch*>* patches = new vector<Patch*>;

	patches->push_back( new Patch(A, AB, E, DA) );
	patches->push_back( new Patch(AB, B, BC, E) );
	patches->push_back( new Patch(BC, C, CD, E) );
	patches->push_back( new Patch(CD, D, DA, E) );

	//cout << "====================" << endl;

	return patches;
}


/**
 * Vraci souradnice vrcholu patche nasypane v jedinem vektoru
 */
vector<float> Patch::getVerticesCoords() {
	vector<float> v;

	v.push_back(vec1.x);
	v.push_back(vec1.y);
	v.push_back(vec1.z);

	v.push_back(vec2.x);
	v.push_back(vec2.y);
	v.push_back(vec2.z);

	v.push_back(vec3.x);
	v.push_back(vec3.y);
	v.push_back(vec3.z);

	v.push_back(vec4.x);
	v.push_back(vec4.y);
	v.push_back(vec4.z);

	return v;
}