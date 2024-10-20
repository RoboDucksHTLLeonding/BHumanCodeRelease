/**
 * @file SetupPoses.h
 *
 * Declaration of a representation that contains information about
 * the pose from which the robots enter the pitch when the game state
 * switches from INITIAL to READY.
 *
 * @author Tim Laue
 */

#pragma once

#include "Platform/BHAssert.h"
#include "Math/Eigen.h"
#include "Streaming/AutoStreamable.h"
#include <vector>

/**
 * @struct SetupPoses
 * A representation that contains a list of poses from which the robots enter
 * the pitch when the game state switches from INITIAL to READY.
 */
STREAMABLE(SetupPoses,
{
  /** The pose of a robot before entering the field */
  STREAMABLE(SetupPose,
  {,
    (int) playerNumber,           /**< The player number of the robot */
    (Vector2f) position,          /**< The position (in global field coordinates) at which the robot is placed */
    (Vector2f) turnedTowards,     /**< The position (in global field coordinates) at which the robot is turned (looking at) */
  });

  /** Implements a debug request to place a player at its setup pose. */
  void draw() const;

  /** Convenience function to find the correct pose given the player number.
   *  The list of poses is not ordered by numbers.
   *  It has to be made sure that the config file contains the entry. Otherwise -> ASSERT!
   *  Exception (for demos and tests): If the list has only one entry, this entry is returned, no matter which number the robot has.
   *  @param number The player number (starting with 1, as the real number)
   *  @return A reference to the pose for setup
   */
  const SetupPose& getPoseOfRobot(int number) const,

  (std::vector<SetupPose>) poses, /**< A list of all available robot poses, not ordered by number */
});
