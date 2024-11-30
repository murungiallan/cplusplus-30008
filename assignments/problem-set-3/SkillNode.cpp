#include "SkillNode.h"
using namespace std;

// Constructor that sets the skill name and level, and initializes next and prev pointers to null
SkillNode::SkillNode(const string& name, int level) : skillName(name), skillLevel(level), next(nullptr), prev(nullptr) {}

// Destructor 
SkillNode::~SkillNode() {}
