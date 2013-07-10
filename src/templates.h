//////////////////////////////////////////////////////////////////////
// The Forgotten Server - a server application for the MMORPG Tibia
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __TEMPLATES_H__
#define __TEMPLATES_H__

#include <set>
#include <map>
#include <boost/thread/recursive_mutex.hpp>

#include "creature.h"
#include "otsystem.h"

template<class T> class AutoList
{
	public:
		AutoList() {}

		virtual ~AutoList() {
			list.clear();
		}

		void addList(T* t) {
			list[t->getID()] = t;
		}

		void removeList(uint32_t _id) {
			list.erase(_id);
		}

		typedef std::map<uint32_t, T*> list_type;

		list_type list;
		typedef typename list_type::iterator listiterator;
};

#endif