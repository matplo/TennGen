// @(#)root/pythia6:$Id$
// Author: Piotr Golonka   17/09/97

/** \class TMCParticle
    \ingroup pythia6

This class serves as a data storage for description of one particle.

It is especially convenient to store information taken from LUJETS common,
which is done by interface class TPythia.

Author: Piotr Golonka   17/09/97
*/

#include "TMCParticle.h"
#include "TPrimary.h"

#ifdef ROOT_TMCParticle_TennGen
   #include <cstdio>
   #warning "Using NoPy6TennGen"
   #ifndef WIN32
   #define pyname pyname_
   #else
   #define pyname PYNAME
   #endif
   void pyname(const Int_t &kf, char *name, const Int_t len)
   {
      sprintf(name, "NoPy6TennGen%d", kf);
   }
#else
   #ifndef WIN32
   #define pyname pyname_
   extern "C" void pyname(const Int_t &kf, const char *name, const Int_t len);
   #else
   #define pyname PYNAME
   extern "C" void pyname(const Int_t &kf, const char *name, const Int_t len);
   #endif
#endif


ClassImp(TMCParticle);

////////////////////////////////////////////////////////////////////////////////

void TMCParticle::ls(Option_t *) const
{
   printf("(%2i,%4i) <-%3i, =>[%3i,%3i]",fKS,fKF,fParent,
          fFirstChild,fLastChild);
   printf(":  p=(%7.3f,%7.3f,%9.3f) ;",fPx,fPy,fPz);

   printf(" E=%8.3f ; m=%7.3f ; V=(%g,%g,%g); t=%g, tau=%g\n",
          fEnergy,fMass,fVx,fVy,fVz,fTime,fLifetime);
}

////////////////////////////////////////////////////////////////////////////////
/// Return name of this particle via Pythia

const char *TMCParticle::GetName() const
{
   static char name[20];
   pyname(fKF,name,16); name[15] = 0;
   for (Int_t i=14;i>0;i--) {
      if (name[i] != ' ') break;
      name[i] = 0;
   }
   return name;
}
