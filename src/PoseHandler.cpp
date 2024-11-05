#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
    {
    }
    // void PoseHandler::Move() noexcept
    // {
    //     point += facing->Move();
    // {
    //     if (pose.heading == 'E')
    //     {
    //         ++pose.x;
    //     }
    //     else if (pose.heading == 'W')
    //     {
    //         --pose.x;
    //     }
    //     else if (pose.heading == 'N')
    //     {
    //         ++pose.y;
    //     }
    //     else if (pose.heading == 'S')
    //     {
    //         --pose.y;
    //     }
    // }
    //}
    void PoseHandler::Forward() noexcept
    {
        point += facing->Move();
    }
    void PoseHandler::Backward() noexcept
    {
        point -= facing->Move();
    }
    void PoseHandler::TurnLeft() noexcept
    {
        facing = &(facing->LeftOne());
        // if (pose.heading == 'E')
        // {
        //     pose.heading = 'N';
        // }
        // else if (pose.heading == 'W')
        // {
        //     pose.heading = 'S';
        // }
        // else if (pose.heading == 'N')
        // {
        //     pose.heading = 'W';
        // }
        // else if (pose.heading == 'S')
        // {
        //     pose.heading = 'E';
        // }
    }
    void PoseHandler::TurnRight() noexcept
    {
        facing = &(facing->RightOne());
        // if (pose.heading == 'E')
        // {
        //     pose.heading = 'S';
        // }
        // else if (pose.heading == 'W')
        // {
        //     pose.heading = 'N';
        // }
        // else if (pose.heading == 'N')
        // {
        //     pose.heading = 'E';
        // }
        // else if (pose.heading == 'S')
        // {
        //     pose.heading = 'W';
        // }
    }
    void PoseHandler::Fast() noexcept
    {
        fast = !fast;
    }
    void PoseHandler::Reverse() noexcept
    {
        reverse = !reverse;
    }
    bool PoseHandler::IsFast() const noexcept
    {
        return fast;
    }
    bool PoseHandler::IsReverse() const noexcept
    {
        return reverse;
    }
    Pose PoseHandler::Query(void) const noexcept
    {
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }
}