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
    Foam::GarzoDuftyConductivity

Description
    \verbatim
    "Dense fluid transport for inelastic hard spheres."
    Garzó, V. and Dufty, J. W. (1999).
    Physical Review. E, Statistical Physics, Plasmas, Fluids, and Related
    Interdisciplinary Topics, 59(5 Pt B):5895–5911
    \endverbatim

    This file is in the \dir
    kineticTheoryModels/conductivityModel/GarzoDufty subdirectory
    inside the subdirectory \dir kineticTheoryModels/conductivityModel
    inside the directory \dir kineticTheoryModels

SourceFiles
    GarzoDuftyConductivity.C

\*---------------------------------------------------------------------------*/

#ifndef GarzoDuftyConductivity_H
#define GarzoDuftyConductivity_H

#include "conductivityModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class GarzoDuftyConductivity Declaration
\*---------------------------------------------------------------------------*/

class GarzoDuftyConductivity
:
    public conductivityModel
{

public:

    //- Runtime type information
    TypeName("GarzoDufty");


    // Constructors

        //- Construct from components
        GarzoDuftyConductivity(const dictionary& dict);


    //- Destructor
    virtual ~GarzoDuftyConductivity();


    // Member Functions

        tmp<volScalarField> kappa
        (
            const volScalarField& alpha,
            const volScalarField& Theta,
            const volScalarField& g0,
            const volScalarField& kappasalt,
            const volScalarField& K,
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
