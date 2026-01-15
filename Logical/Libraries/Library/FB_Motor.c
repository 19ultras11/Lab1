
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Functional block of motor */
void FB_Motor(struct FB_Motor* inst)
{
	REAL A = (inst->u / inst->ke - inst->w) / inst->Tm;
	inst->integrator.in = A;
	FB_Integrator(&inst->integrator);	
	inst->w = inst->integrator.out;
}
