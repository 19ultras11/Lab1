
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif

/* voltage limit function */
REAL VoltageLimitation(REAL max, REAL x)
{
	if (x > max)
	{
		x = max;
	}
	if (x < -max)
	{
		x = -max;
	}
	return x;
}

void FB_Regulator(struct FB_Regulator* inst)
{
	REAL A = inst->e * inst->k_p;
	REAL B = inst->e * inst->k_i;
	A = VoltageLimitation(inst->max_abs_value, A);
	inst->integrator.in = B + inst->iyOld;
	FB_Integrator(&inst->integrator);
	A = A + inst->integrator.out;
	inst->u = VoltageLimitation(inst->max_abs_value, A);
	inst->iyOld = inst->u - A;
}


