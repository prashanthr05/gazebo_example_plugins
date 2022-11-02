#include "WorldGravity.h"
#include <gazebo/physics/World.hh>

#include <iostream>

using namespace gazebo;

void WorldGravity::Load(physics::WorldPtr _parent, sdf::ElementPtr sdf)
{
    m_world = _parent;
    m_gravity.Set(0.0, 0.0, -9.81);
    m_world->SetGravity(m_gravity);
    m_updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&WorldGravity::OnUpdate, this));
}

void WorldGravity::OnUpdate()
{
    m_counter +=1;

    if (m_counter == 100)
    {
	m_gravity.Set(m_gravity.X(), m_gravity.Y(), -m_gravity.Z());
	m_counter = 0;
	m_world->SetGravity(m_gravity);
	std::cout << "[Inside WorldGravity Plugin] Switching World Gravity Z to " << m_gravity.Z() <<  std::endl;
    }
}

