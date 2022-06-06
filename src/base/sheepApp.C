#include "sheepApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
sheepApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

sheepApp::sheepApp(InputParameters parameters) : MooseApp(parameters)
{
  sheepApp::registerAll(_factory, _action_factory, _syntax);
}

sheepApp::~sheepApp() {}

void
sheepApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"sheepApp"});
  Registry::registerActionsTo(af, {"sheepApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sheepApp::registerApps()
{
  registerApp(sheepApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sheepApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sheepApp::registerAll(f, af, s);
}
extern "C" void
sheepApp__registerApps()
{
  sheepApp::registerApps();
}
