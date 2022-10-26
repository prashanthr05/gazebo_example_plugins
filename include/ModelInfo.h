#ifndef MODEL_INFO_H
#define MODEL_INFO_H

#include <gazebo/gazebo.hh>

namespace gazebo
{
    class ModelInfo : public ModelPlugin
    {
    public:
        void Load(physics::ModelPtr _parent, sdf::ElementPtr sdf);
        void OnUpdate();    
    private:
        physics::ModelPtr m_model;
        event::ConnectionPtr m_updateConnection;
    };
    
    
    // Register this plugin with the simulator
    GZ_REGISTER_MODEL_PLUGIN(ModelInfo)
}

#endif // MODEL_INFO_H

