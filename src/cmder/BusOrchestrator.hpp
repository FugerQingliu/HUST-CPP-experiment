#pragma once
#include "NormalOrchestrator.hpp"

namespace adas
{
    class BusOrchestrator : public NormalOrchestrator
    {
        public :
        ActionGroup TurnLeft(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAcition(GetStepAction(poseHandler));
            if(poseHandler.IsReverse())
                actionGroup.PushAcition(ActionType::TURNRIGHT_ACTION);
            else
                actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            return actionGroup;
        }
        ActionGroup TurnRight(const PoseHandler& poseHandler)const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            actionGroup.PushAcition(GetStepAction(poseHandler));
            if(poseHandler.IsReverse())
                actionGroup.PushAcition(ActionType::TURNLEFT_ACTION);
            else
                actionGroup.PushAcition(ActionType::TURNRIGHT_ACTION);
            return actionGroup;
        }
    };
}