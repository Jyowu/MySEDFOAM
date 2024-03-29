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
    Foam::conductivityModel

Description
    This file is in the \dir
    kineticTheoryModels/conductivityModel/conductivityModel subdirectory
    inside the subdirectory \dir kineticTheoryModels/conductivityModel
    inside the directory \dir kineticTheoryModels
SourceFiles
    conductivityModel.C

\*---------------------------------------------------------------------------*/

#ifndef conductivityModel_H
#define conductivityModel_H

#include "dictionary.H"
#include "volFields.H"
#include "dimensionedTypes.H"
#include "runTimeSelectionTables.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class conductivityModel Declaration
\*---------------------------------------------------------------------------*/

class conductivityModel
{
    // Private member functions

        //- Disallow default bitwise copy construct
        conductivityModel(const conductivityModel&);

        //- Disallow default bitwise assignment
        void operator=(const conductivityModel&);


protected:

    // Protected data

        const dictionary& dict_;


public:

    //- Runtime type information
    TypeName("conductivityModel");

    // Declare runtime constructor selection table
    declareRunTimeSelectionTable
    (
        autoPtr,
        conductivityModel,
        dictionary,
        (
            const dictionary& dict
        ),
        (dict)
    );


    // Constructors

        //- Construct from components
        conductivityModel(const dictionary& dict);


    // Selectors

        static autoPtr<conductivityModel> New
        (
            const dictionary& dict
        );


    //- Destructor
    virtual ~conductivityModel();


    // Member Functions

        virtual tmp<volScalarField> kappa
        (
            const volScalarField& alpha,
            const volScalarField& Theta,
            const volScalarField& g0,
            const volScalarField& kappasalt,
            const volScalarField& K,
            const dimensionedScalar& rhoa,
            const dimensionedScalar& da,
            const dimensionedScalar& e
        ) const = 0;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
