/*--------------------------------*- C++ -*----------------------------------*\
| =========                 |                                                 |
| \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |
|  \\    /   O peration     | Version:  2.1.0                                 |
|   \\  /    A nd           | Web:      www.OpenFOAM.org                      |
|    \\/     M anipulation  |                                                 |
\*---------------------------------------------------------------------------*/
FoamFile
{
    version     2.0;
    format      ascii;
    class       volScalarField;
    location    "0";
    object      epsilon;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

dimensions      [0 2 -3 0 0 0 0];

internalField   uniform 1e-10; 

boundaryField
{
    inandouthalf11
    {
	type		zeroGradient;
    } 
    inandouthalf12
    {
        type            zeroGradient;
    }
    inandouthalf21
    {
        type            zeroGradient;
    }
    inandouthalf22
    {
        type            zeroGradient;
    }
    top
    {
//        type            symmetryPlane;
        type            zeroGradient;
    }
    walls
    {
        type            zeroGradient;
    }
    frontAndBackPlanes
    {
        type            empty;
    }
}


// ************************************************************************* //
