/*
 * This file is part of phantom-drivers.
 *
 * phantom-drivers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * phantom-drivers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with phantom-drivers.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Phantom Library: iterator to iterate over FirewireDevices, Mac OS X implementation
 */

#pragma once

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOCFPlugIn.h>
#include <IOKit/firewire/IOFireWireLib.h>
#include <IOKit/firewire/IOFireWireLibIsoch.h>

#include "DeviceIterator.h"
#include "FirewireDevice.h"

namespace LibPhantom
{
  class DeviceIteratorMacOSX : public DeviceIterator
  {
  public:
    //TODO: friend??
    DeviceIteratorMacOSX();
  public:
    FirewireDevice* next();
  private:
    io_iterator_t deviceIterator;
    io_iterator_t unitIterator;

  };
}

