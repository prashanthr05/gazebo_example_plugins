#include "ModelInfo.h"
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/Joint.hh>
#include <gazebo/physics/Link.hh>
#include <iostream>
#include <vector>

using namespace gazebo;

void ModelInfo::Load(physics::ModelPtr _parent, sdf::ElementPtr sdf)
{
    m_model = _parent;
    m_updateConnection = event::Events::ConnectWorldUpdateBegin(std::bind(&ModelInfo::OnUpdate, this));
}

void ModelInfo::OnUpdate()
{
    auto nrJoints = m_model->GetJointCount();
    auto joints = m_model->GetJoints();
    if (nrJoints != joints.size())
    {
        std::cerr << "[ModelInfo] Joints size mismatch!" << std::endl;
        return;
    }
    
    std::cout << "List of Joints: " << std::endl;
    for (auto joint : joints)
    {
        std::cout << "- " << joint->GetName() << std::endl; 
    }
    
    auto links = m_model->GetLinks();
    std::cout << "List of Links: " << std::endl;
    for (auto link : links)
    {
        std::cout << "- " << link->GetName() << std::endl; 
    }
}

