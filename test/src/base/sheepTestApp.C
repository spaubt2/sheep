//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sheepTestApp.h"
#include "sheepApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
sheepTestApp::validParams()
{
  InputParameters params = sheepApp::validParams();
  return params;
}

sheepTestApp::sheepTestApp(InputParameters parameters) : MooseApp(parameters)
{
  sheepTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sheepTestApp::~sheepTestApp() {}

void
sheepTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sheepApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sheepTestApp"});
    Registry::registerActionsTo(af, {"sheepTestApp"});
  }
}

void
sheepTestApp::registerApps()
{
  registerApp(sheepApp);
  registerApp(sheepTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sheepTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sheepTestApp::registerAll(f, af, s);
}
extern "C" void
sheepTestApp__registerApps()
{
  sheepTestApp::registerApps();
}
