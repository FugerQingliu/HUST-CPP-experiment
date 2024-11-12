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
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

        std::for_each
        (
            cmders.begin(),
            cmders.end(),
            [this](const Cmder &cmder) noexcept
            {
                cmder(poseHandler).DoOperate(poseHandler);
            }
        );
    }
}