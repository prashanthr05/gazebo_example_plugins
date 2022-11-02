#ifndef WORLD_GRAVITY_H
#define WORLD_GRAVITY_H

#include <gazebo/gazebo.hh>

namespace gazebo
{
    class WorldGravity : public WorldPlugin
    {
    public:
        void Load(physics::WorldPtr _parent, sdf::ElementPtr sdf);
        void OnUpdate();
    private:
        physics::WorldPtr m_world;
        event::ConnectionPtr m_updateConnection;
        int m_counter{0};
        ignition::math::Vector3d m_gravity;
    };


    // Register this plugin with the simulator
    GZ_REGISTER_WORLD_PLUGIN(WorldGravity)
}

#endif // MODEL_INFO_H

