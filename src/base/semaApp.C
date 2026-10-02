#include "semaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
semaApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

semaApp::semaApp(const InputParameters & parameters) : MooseApp(parameters)
{
  semaApp::registerAll(_factory, _action_factory, _syntax);
}

semaApp::~semaApp() {}

void
semaApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<semaApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"semaApp"});
  Registry::registerActionsTo(af, {"semaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
semaApp::registerApps()
{
  registerApp(semaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
semaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  semaApp::registerAll(f, af, s);
}
extern "C" void
semaApp__registerApps()
{
  semaApp::registerApps();
}
