/**
 * The Forgotten Server - a server application for the MMORPG Tibia
 * Copyright (C) 2013  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __OTSERV_DEPOTCHEST_H__
#define __OTSERV_DEPOTCHEST_H__

#include "container.h"

class DepotChest : public Container
{
	public:
		DepotChest(uint16_t _type);
		~DepotChest();

		DepotChest* getDepotChest() {
			return this;
		}
		const DepotChest* getDepotChest() const {
			return this;
		}

		//serialization
		void setMaxDepotItems(uint32_t maxitems) {
			maxDepotItems = maxitems;
		}

		//cylinder implementations
		ReturnValue __queryAdd(int32_t index, const Thing* thing, uint32_t count,
		                       uint32_t flags, Creature* actor = nullptr) const;

		void postAddNotification(Thing* thing, const Cylinder* oldParent, int32_t index, cylinderlink_t link = LINK_OWNER);
		void postRemoveNotification(Thing* thing, const Cylinder* newParent, int32_t index, bool isCompleteRemoval, cylinderlink_t link = LINK_OWNER);

		//overrides
		bool canRemove() const {
			return false;
		}

	private:
		uint32_t maxDepotItems;
};

#endif

