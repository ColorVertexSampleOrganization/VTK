/*=========================================================================

  Program:   Visualization Library
  Module:    CleanP.hh
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

This file is part of the Visualization Library. No part of this file
or its contents may be copied, reproduced or altered in any way
without the express written consent of the authors.

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen 1993, 1994 

=========================================================================*/
// .NAME vlCleanPolyData - merge duplicate points and remove degenerate primitives
// .SECTION Description
// vlCleanPolyData is a filter that takes as input polygonal data and 
// generates polygonal as output. vlCleanPolyData merges duplicate 
// points (within specified tolerance) and transforms degenerate 
// topology into appropriate form (for example, triangle is converted
// into line if two points of triangle are merged).
// .SECTION Caveats
// Merging points can alter topology including introducing non-manifold 
// forms. Tolerance should be chosen carefully to avoid these problems.

#ifndef __vlCleanPolyData_h
#define __vlCleanPolyData_h

#include "P2PF.hh"

class vlCleanPolyData : public vlPolyToPolyFilter
{
public:
  vlCleanPolyData();
  ~vlCleanPolyData();
  char *GetClassName() {return "vlCleanPolyData";};
  void PrintSelf(ostream& os, vlIndent indent);

  // Description:
  // Specify tolerance in terms of percentage of bounding box.
  vlSetClampMacro(Tolerance,float,0.0,1.0);
  vlGetMacro(Tolerance,float);

  // Description:
  // Specify a spatial locator for speeding the search process. By
  // default an instance of vlLocator is used.
  vlSetObjectMacro(Locator,vlLocator);
  vlGetObjectMacro(Locator,vlLocator);

protected:
  // Usual data generation method
  void Execute();

  float Tolerance;
  vlLocator *Locator;
};

#endif


