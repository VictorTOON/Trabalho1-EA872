#include "massa-mola-amortecimento.h"
#include "sdl_renderer.h"
int main(){		
	auto bloco = std::shared_ptr<Block>(new Block(.5,4,10,.1));
	auto mola = std::shared_ptr<Spring>(new Spring(.5));
	bloco->changeBlockDim(20,20);

	System s(bloco, mola, 15);
	s.simulate(5000);
	return 0;
}
