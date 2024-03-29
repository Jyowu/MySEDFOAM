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
    Foam::SyamlalRogersOBrienPressure

Description
    This file is in the \dir
    kineticTheoryModels/granularPressureModel/SyamlalRogersOBrien
    subdirectory inside the subdirectory
    \dir kineticTheoryModels/granularPressureModel inside the directory
    \dir kineticTheoryModels

SourceFiles
    SyamlalRogersOBrienPressure.C

\*---------------------------------------------------------------------------*/

#ifndef SyamlalRogersOBrienPressure_H
#define SyamlalRogersOBrienPressure_H

#include "granularPressureModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class SyamlalRogersOBrienPressure Declaration
\*---------------------------------------------------------------------------*/

class SyamlalRogersOBrienPressure
:
    public granularPressureModel
{

public:

    //- Runtime type information
    TypeName("SyamlalRogersOBrien");


    // Constructors

        //- Construct from components
        SyamlalRogersOBrienPressure(const dictionary& dict);


    //- Destructor
    virtual ~SyamlalRogersOBrienPressure();


    // Member Functions

        tmp<volScalarField> granularPressureCoeff
        (
            const volScalarField& alpha,
            const volScalarField& g0,
            const dimensionedScalar& rhoa,
            const dimensionedScalar& e
        ) const;

        tmp<volScalarField> granularPressureCoeffPrime
        (
            const volScalarField& alpha,
            const volScalarField& g0,
            const volScalarField& g0prime,
            const dimensionedScalar& rhoa,
            const dimensionedScalar& e
        ) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
