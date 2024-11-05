#include "ExecutorImpl.hpp"
#include <new>
#include <memory>
#include "Command.hpp"

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose){}
    // Pose ExecutorImpl::Query(void) const noexcept
    // {
    //     return pose;
    // }
    Pose ExecutorImpl :: Query() const noexcept
    {
        return poseHandler.Query();
    }
    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        std::unordered_map<char,std::unique_ptr<ICommand>> cmderMap;
        cmderMap.emplace('M',std::make_unique<MoveCommand>());
        cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
        cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
        cmderMap.emplace('F', std::make_unique<FastCommand>());
        for (const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);
            if(it != cmderMap.end())
            {
                it->second->DoOperate(poseHandler);
            }
            // std::unique_ptr<ICommand> cmder;
            // if (cmd == 'M')
            // // {
            // //     if (pose.heading == 'E')
            // //     {
            // //         ++pose.x;
            // //     }
            // //     else if (pose.heading == 'W')
            // //     {
            // //         --pose.x;
            // //     }
            // //     else if (pose.heading == 'N')
            // //     {
            // //         ++pose.y;
            // //     }
            // //     else if (pose.heading == 'S')
            // //     {
            // //         --pose.y;
            // //     }
            // // }
            // {
            //     cmder = std::make_unique<MoveCommand>();
            // }
            // else if (cmd == 'L')
            // {
            //     // if (pose.heading == 'E')
            //     // {
            //     //     pose.heading = 'N';
            //     // }
            //     // else if (pose.heading == 'W')
            //     // {
            //     //     pose.heading = 'S';
            //     // }
            //     // else if (pose.heading == 'N')
            //     // {
            //     //     pose.heading = 'W';
            //     // }
            //     // else if (pose.heading == 'S')
            //     // {
            //     //     pose.heading = 'E';
            //     // }
            //     cmder = std::make_unique<TurnLeftCommand>();
            // }
            // else if (cmd == 'R')
            // {
            //     // if (pose.heading == 'E')
            //     // {
            //     //     pose.heading = 'S';
            //     // }
            //     // else if (pose.heading == 'W')
            //     // {
            //     //     pose.heading = 'N';
            //     // }
            //     // else if (pose.heading == 'N')
            //     // {
            //     //     pose.heading = 'E';
            //     // }
            //     // else if (pose.heading == 'S')
            //     // {
            //     //     pose.heading = 'W';
            //     // }
            //     cmder = std::make_unique<TurnRightCommand>();
            // }
            // else if (cmd == 'F')
            // {
            //     cmder = std::make_unique<FastCommand>();
            // }
            // if (cmder)
            // {
            //     cmder->DoOperate(poseHandler);
            // }
        }
    }
    // void ExecutorImpl::Move() noexcept
    // {
    //     {
    //         if (pose.heading == 'E')
    //         {
    //             ++pose.x;
    //         }
    //         else if (pose.heading == 'W')
    //         {
    //             --pose.x;
    //         }
    //         else if (pose.heading == 'N')
    //         {
    //             ++pose.y;
    //         }
    //         else if (pose.heading == 'S')
    //         {
    //             --pose.y;
    //         }
    //     }
    // }
    // void ExecutorImpl::TurnLeft() noexcept
    // {
    //     if (pose.heading == 'E')
    //     {
    //         pose.heading = 'N';
    //     }
    //     else if (pose.heading == 'W')
    //     {
    //         pose.heading = 'S';
    //     }
    //     else if (pose.heading == 'N')
    //     {
    //         pose.heading = 'W';
    //     }
    //     else if (pose.heading == 'S')
    //     {
    //         pose.heading = 'E';
    //     }
    // }
    // void ExecutorImpl::TurnRight() noexcept
    // {
    //     if (pose.heading == 'E')
    //     {
    //         pose.heading = 'S';
    //     }
    //     else if (pose.heading == 'W')
    //     {
    //         pose.heading = 'N';
    //     }
    //     else if (pose.heading == 'N')
    //     {
    //         pose.heading = 'E';
    //     }
    //     else if (pose.heading == 'S')
    //     {
    //         pose.heading = 'W';
    //     }
    // }
    // void ExecutorImpl::Fast() noexcept
    // {
    //     fast = !fast;
    // }
    // bool ExecutorImpl::IsFast() const noexcept
    // {
    //     return fast;
    // }
}