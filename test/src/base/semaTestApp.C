//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "semaTestApp.h"
#include "semaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
semaTestApp::validParams()
{
  InputParameters params = semaApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

semaTestApp::semaTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  semaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

semaTestApp::~semaTestApp() {}

void
semaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  semaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"semaTestApp"});
    Registry::registerActionsTo(af, {"semaTestApp"});
  }
}

void
semaTestApp::registerApps()
{
  registerApp(semaApp);
  registerApp(semaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
semaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  semaTestApp::registerAll(f, af, s);
}
extern "C" void
semaTestApp__registerApps()
{
  semaTestApp::registerApps();
}
