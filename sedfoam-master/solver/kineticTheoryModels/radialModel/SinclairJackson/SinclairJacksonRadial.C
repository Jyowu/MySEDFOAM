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

\*---------------------------------------------------------------------------*/

#include "SinclairJacksonRadial.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(SinclairJacksonRadial, 0);

    addToRunTimeSelectionTable
    (
        radialModel,
        SinclairJacksonRadial,
        dictionary
    );
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::SinclairJacksonRadial::SinclairJacksonRadial(const dictionary& dict)
:
    radialModel(dict)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::SinclairJacksonRadial::~SinclairJacksonRadial()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField> Foam::SinclairJacksonRadial::g0
(
    const volScalarField& alpha,
    const dimensionedScalar& alphaMax,
    const dimensionedScalar& muPart
) const
{
    return 1.0/mag(1.0 - pow(alpha/alphaMax, 1.0/3.0));
}


Foam::tmp<Foam::volScalarField> Foam::SinclairJacksonRadial::g0prime
(
    const volScalarField& alpha,
    const dimensionedScalar& alphaMax,
    const dimensionedScalar& muPart
) const
{
    return (1.0/3.0)*pow(max(alpha, scalar(1e-9))/alphaMax, -2.0/3.0)
          /(alphaMax*sqr(1.0 - pow(alpha/alphaMax, 1.0/3.0)));
}


// ************************************************************************* //
