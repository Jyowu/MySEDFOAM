/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::GarzoDuftyPseudoConductivity

Description
    \verbatim
    "Dense fluid transport for inelastic hard spheres."
    Garzó, V. and Dufty, J. W. (1999).
    Physical Review. E, Statistical Physics, Plasmas, Fluids, and Related
    Interdisciplinary Topics, 59(5 Pt B):5895–5911
    \endverbatim

    This file is in the
    \dir kineticTheoryModels/pseudoConductivityModel/GarzoDufty
    directory

SourceFiles
    GarzoDuftyPseudoConductivity.C

\*---------------------------------------------------------------------------*/

#ifndef GarzoDuftyPseudoConductivity_H
#define GarzoDuftyPseudoConductivity_H

#include "pseudoConductivityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class GarzoDuftyPseudoConductivity Declaration
\*---------------------------------------------------------------------------*/

class GarzoDuftyPseudoConductivity
:
    public pseudoConductivityModel
{

public:

    //- Runtime type information
    TypeName("GarzoDufty");


    // Constructors

        //- Construct from components
        GarzoDuftyPseudoConductivity(const dictionary& dict);


    //- Destructor
    virtual ~GarzoDuftyPseudoConductivity();


    // Member Functions

        tmp<volScalarField> kappaAlpha
        (
            const volScalarField& alpha,
            const volScalarField& Theta,
            const volScalarField& g0,
            const volScalarField& g0prime,
            const dimensionedScalar& rhoa,
            const dimensionedScalar& da,
            const dimensionedScalar& e
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
