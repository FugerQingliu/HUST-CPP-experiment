#pragma once
#include "NormalOrchestrator.hpp"

namespace adas
{
    class SportsCarOrchestrator : public NormalOrchestrator
    {
        public :
        ActionGroup Move(const PoseHandler& poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAcition(GetStepAction(poseHandler));
            actionGroup.PushAcition(GetStepAction(poseHandler));
            return actionGroup;
        }
        ActionGroup TurnLeft(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            if(poseHandler.IsReverse())
                actionGroup.PushAcition(ActionType::TURNRIGHT_ACTION);
            else
                actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            actionGroup.PushAcition(GetStepAction(poseHandler));
            return actionGroup;
        }
        ActionGroup TurnRight(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            if(poseHandler.IsReverse())
                actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            else
                actionGroup.PushAcition(ActionType::TURNRIGHT_ACTION);
            actionGroup.PushAcition(GetStepAction(poseHandler));
            return actionGroup;
        }
    };
}