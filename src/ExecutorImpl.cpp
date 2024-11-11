#include "ExecutorImpl.hpp"
#include <algorithm>
#include "CmderFactory.hpp"
#include "Singleton.hpp"
// #include <new>
// #include <memory>
// #include "Command.hpp"

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}

    Pose ExecutorImpl ::Query() const noexcept
    {
        return poseHandler.Query();
    }
    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        // std::unordered_map<char, std::function<void(PoseHandler &poseHandler)>> cmderMap
        // {
        //     {'M', MoveCommand()},
        //     {'L', TurnLeftCommand()},
        //     {'R', TurnRightCommand()},
        //     {'F', FastCommand()},
        //     {'B', ReverseCommand()}
        // };

        // for (const auto cmd : commands)
        // {
        //     const auto it = cmderMap.find(cmd);
        //     if (it != cmderMap.end())
        //     {
        //         it->second(poseHandler);
        //     }
        // }
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

        std::for_each
        (
            cmders.begin(),
            cmders.end(),
            [this](const std::function<void(PoseHandler &poseHandler)> &cmder) noexcept
            {
                cmder(poseHandler);
            }
        );
    }
}