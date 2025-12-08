#pragma once
#include "Particle.h"
#include <vector>



// erase et remove_if

class ParticleEmitter
{
private:

	std::vector<Particle*> allParticle;

public:

	void Init();

	void dysplayParticle();
	
	void Update();

};

