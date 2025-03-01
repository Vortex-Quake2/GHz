/*
==============================================================================

INFANTRY

==============================================================================
*/

#include "g_local.h"
#include "../../quake2/monsterframes/m_infantry.h"


void InfantryMachineGun (edict_t *self);


static int	sound_pain1;
static int	sound_pain2;
static int	sound_die1;
static int	sound_die2;

static int	sound_gunshot;
static int	sound_weapon_cock;
static int	sound_punch_swing;
static int	sound_punch_hit;
static int	sound_sight;
static int	sound_search;
static int	sound_idle;


mframe_t infantry_frames_stand [] =
{
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL,
	drone_ai_stand, 0, NULL
};
mmove_t infantry_move_stand = {FRAME_stand50, FRAME_stand71, infantry_frames_stand, NULL};

void infantry_stand (edict_t *self)
{
	self->monsterinfo.currentmove = &infantry_move_stand;
}


mframe_t infantry_frames_fidget [] =
{
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 3,  NULL,
	drone_ai_stand, 6,  NULL,
	drone_ai_stand, 3,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, -1, NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, -2, NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, -1, NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, -1, NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, -1, NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 1,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, -1, NULL,
	drone_ai_stand, -1, NULL,
	drone_ai_stand, 0,  NULL,
	drone_ai_stand, -3, NULL,
	drone_ai_stand, -2, NULL,
	drone_ai_stand, -3, NULL,
	drone_ai_stand, -3, NULL,
	drone_ai_stand, -2, NULL
};
mmove_t infantry_move_fidget = {FRAME_stand01, FRAME_stand49, infantry_frames_fidget, infantry_stand};

void infantry_fidget (edict_t *self)
{
	self->monsterinfo.currentmove = &infantry_move_fidget;
	gi.sound (self, CHAN_VOICE, sound_idle, 1, ATTN_IDLE, 0);
}

mframe_t infantry_frames_walk [] =
{
	drone_ai_walk, 5,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 5,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 5,  NULL,
	drone_ai_walk, 6,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 4,  NULL,
	drone_ai_walk, 5,  NULL
};
mmove_t infantry_move_walk = {FRAME_walk03, FRAME_walk14, infantry_frames_walk, NULL};

void infantry_walk (edict_t *self)
{
	if (!self->goalentity)
		self->goalentity = world;

	self->monsterinfo.currentmove = &infantry_move_walk;
}

mframe_t infantry_frames_run [] =
{
	drone_ai_run, 25, NULL,
	drone_ai_run, 25, NULL,
	drone_ai_run, 25,  NULL,
	drone_ai_run, 25,  NULL,
	drone_ai_run, 25, NULL,
	drone_ai_run, 25, NULL,
	drone_ai_run, 25,  NULL,
	drone_ai_run, 25,  NULL
};
mmove_t infantry_move_run = {FRAME_run01, FRAME_run08, infantry_frames_run, NULL};

void infantry_run (edict_t *self)
{
	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
		self->monsterinfo.currentmove = &infantry_move_stand;
	else
		self->monsterinfo.currentmove = &infantry_move_run;
}

vec3_t	aimangles[] =
{
	0.0, 5.0, 0.0,
	10.0, 15.0, 0.0,
	20.0, 25.0, 0.0,
	25.0, 35.0, 0.0,
	30.0, 40.0, 0.0,
	30.0, 45.0, 0.0,
	25.0, 50.0, 0.0,
	20.0, 40.0, 0.0,
	15.0, 35.0, 0.0,
	40.0, 35.0, 0.0,
	70.0, 35.0, 0.0,
	90.0, 35.0, 0.0
};

void InfantryMachineGun (edict_t *self)
{
	vec3_t	start, forward, right, vec;
	int		damage, flash_number;

	damage = 10 + 1*self->monsterinfo.level; // dmg: infantry_machinegun

	if (self->s.frame == FRAME_attak111)
	{
		flash_number = MZ2_INFANTRY_MACHINEGUN_1;
		MonsterAim(self, 0.8, 0, false, flash_number, forward, start);
	}
	else
	{
		flash_number = MZ2_INFANTRY_MACHINEGUN_2 + (self->s.frame - FRAME_death211);

		AngleVectors (self->s.angles, forward, right, NULL);
		G_ProjectSource (self->s.origin, monster_flash_offset[flash_number], forward, right, start);

		VectorSubtract (self->s.angles, aimangles[flash_number-MZ2_INFANTRY_MACHINEGUN_2], vec);
		AngleVectors (vec, forward, NULL, NULL);
	}

	monster_fire_bullet (self, start, forward, damage, damage, 
		DEFAULT_BULLET_HSPREAD, DEFAULT_BULLET_VSPREAD, flash_number);
}

void infantry_sight (edict_t *self, edict_t *other)
{
	gi.sound (self, CHAN_BODY, sound_sight, 1, ATTN_NORM, 0);
}

void infantry_dead (edict_t *self)
{
	VectorSet (self->mins, -16, -16, -24);
	VectorSet (self->maxs, 16, 16, -8);
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	gi.linkentity (self);
	M_PrepBodyRemoval(self);
}

mframe_t infantry_frames_death1 [] =
{
	ai_move, -4, NULL,
	ai_move, 0,  NULL,
	ai_move, 0,  NULL,
	ai_move, -1, NULL,
	ai_move, -4, NULL,
	ai_move, 0,  NULL,
	ai_move, 0,  NULL,
	ai_move, 0,  NULL,
	ai_move, -1, NULL,
	ai_move, 3,  NULL,
	ai_move, 1,  NULL,
	ai_move, 1,  NULL,
	ai_move, -2, NULL,
	ai_move, 2,  NULL,
	ai_move, 2,  NULL,
	ai_move, 9,  NULL,
	ai_move, 9,  NULL,
	ai_move, 5,  NULL,
	ai_move, -3, NULL,
	ai_move, -3, NULL
};
mmove_t infantry_move_death1 = {FRAME_death101, FRAME_death120, infantry_frames_death1, infantry_dead};

// Off with his head
mframe_t infantry_frames_death2 [] =
{
	ai_move, 0,   NULL,
	ai_move, 1,   NULL,
	ai_move, 5,   NULL,
	ai_move, -1,  NULL,
	ai_move, 0,   NULL,
	ai_move, 1,   NULL,
	ai_move, 1,   NULL,
	ai_move, 4,   NULL,
	ai_move, 3,   NULL,
	ai_move, 0,   NULL,
	ai_move, -2,  InfantryMachineGun,
	ai_move, -2,  InfantryMachineGun,
	ai_move, -3,  InfantryMachineGun,
	ai_move, -1,  InfantryMachineGun,
	ai_move, -2,  InfantryMachineGun,
	ai_move, 0,   InfantryMachineGun,
	ai_move, 2,   InfantryMachineGun,
	ai_move, 2,   InfantryMachineGun,
	ai_move, 3,   InfantryMachineGun,
	ai_move, -10, InfantryMachineGun,
	ai_move, -7,  InfantryMachineGun,
	ai_move, -8,  InfantryMachineGun,
	ai_move, -6,  NULL,
	ai_move, 4,   NULL,
	ai_move, 0,   NULL
};
mmove_t infantry_move_death2 = {FRAME_death201, FRAME_death225, infantry_frames_death2, infantry_dead};

mframe_t infantry_frames_death3 [] =
{
	ai_move, 0,   NULL,
	ai_move, 0,   NULL,
	ai_move, 0,   NULL,
	ai_move, -6,  NULL,
	ai_move, -11, NULL,
	ai_move, -3,  NULL,
	ai_move, -11, NULL,
	ai_move, 0,   NULL,
	ai_move, 0,   NULL
};
mmove_t infantry_move_death3 = {FRAME_death301, FRAME_death309, infantry_frames_death3, infantry_dead};


void infantry_die (edict_t *self, edict_t *inflictor, edict_t *attacker, int damage, vec3_t point)
{
	int		n;

	M_Notify(self);

#ifdef OLD_NOLAG_STYLE
	if (nolag->value)
	{
		M_Remove(self, false, true);
		return;
	}
#endif

// check for gib
	if (self->health <= self->gib_health)
	{
		gi.sound (self, CHAN_VOICE, gi.soundindex ("misc/udeath.wav"), 1, ATTN_NORM, 0);
		for (n= 0; n < 2; n++)
			ThrowGib (self, "models/objects/gibs/bone/tris.md2", damage, GIB_ORGANIC);
		for (n= 0; n < 4; n++)
			ThrowGib (self, "models/objects/gibs/sm_meat/tris.md2", damage, GIB_ORGANIC);
		ThrowHead (self, "models/objects/gibs/head2/tris.md2", damage, GIB_ORGANIC);

#ifdef OLD_NOLAG_STYLE
		M_Remove(self, false, false);
#else
		if (nolag->value)
			M_Remove(self, false, true);
		else
			M_Remove(self, false, false);
#endif
		return;
	}

	if (self->deadflag == DEAD_DEAD)
		return;

	DroneList_Remove(self);

// regular death
	self->deadflag = DEAD_DEAD;
	self->takedamage = DAMAGE_YES;

	n = randomMT() % 3;
	if (n == 0)
	{
		self->monsterinfo.currentmove = &infantry_move_death1;
		gi.sound (self, CHAN_VOICE, sound_die2, 1, ATTN_NORM, 0);
	}
	else if (n == 1)
	{
		self->monsterinfo.currentmove = &infantry_move_death2;
		gi.sound (self, CHAN_VOICE, sound_die1, 1, ATTN_NORM, 0);
	}
	else
	{
		self->monsterinfo.currentmove = &infantry_move_death3;
		gi.sound (self, CHAN_VOICE, sound_die2, 1, ATTN_NORM, 0);
	}

	if (self->activator && !self->activator->client)
	{
		self->activator->num_monsters_real--;
		// gi.bprintf(PRINT_HIGH, "releasing %p (%d)\n", self, self->activator->num_monsters_real);
	}

}


void infantry_duck_down (edict_t *self)
{
	if (self->monsterinfo.aiflags & AI_DUCKED)
		return;
	self->monsterinfo.aiflags |= AI_DUCKED;
	self->maxs[2] -= 32;
	self->takedamage = DAMAGE_YES;
	self->monsterinfo.pausetime = level.time + 1;
	gi.linkentity (self);
}

void infantry_duck_hold (edict_t *self)
{
	if (level.time >= self->monsterinfo.pausetime)
		self->monsterinfo.aiflags &= ~AI_HOLD_FRAME;
	else
		self->monsterinfo.aiflags |= AI_HOLD_FRAME;
}

void infantry_duck_up (edict_t *self)
{
	self->monsterinfo.aiflags &= ~AI_DUCKED;
	self->maxs[2] += 32;
	self->takedamage = DAMAGE_AIM;
	gi.linkentity (self);
}

mframe_t infantry_frames_duck [] =
{
	ai_move, -2, infantry_duck_down,
	ai_move, -5, infantry_duck_hold,
	ai_move, 3,  NULL,
	ai_move, 4,  infantry_duck_up,
	ai_move, 0,  NULL
};
mmove_t infantry_move_duck = {FRAME_duck01, FRAME_duck05, infantry_frames_duck, infantry_run};

void infantry_cock_gun (edict_t *self)
{
	//int		n;

	gi.sound (self, CHAN_WEAPON, sound_weapon_cock, 1, ATTN_NORM, 0);
	//n = (randomMT() & 15) + 3 + 7;
	//self->monsterinfo.pausetime = level.time + (GetRandom(10, 50) * FRAMETIME);
	//self->monsterinfo.attack_finished = self->monsterinfo.pausetime + 2.0;
}

void infantry_fire (edict_t *self)
{
	InfantryMachineGun (self);

	if (level.time >= self->monsterinfo.pausetime || !visible(self, self->enemy))
		self->monsterinfo.aiflags &= ~AI_HOLD_FRAME;
	else
		self->monsterinfo.aiflags |= AI_HOLD_FRAME;
}

mframe_t infantry_frames_attack1 [] =
{
	//ai_charge, 4,  NULL,
	//ai_charge, -1, NULL,
	//ai_charge, -1, NULL,
	//ai_charge, 0,  infantry_cock_gun,
	//ai_charge, -1, NULL,
	//ai_charge, 1,  NULL,
	//ai_charge, 1,  NULL,
	//ai_charge, 2,  NULL,
	//ai_charge, -2, NULL,
	//ai_charge, -3, NULL,
	ai_charge, 1,  infantry_fire,
	ai_charge, 5,  NULL,
	ai_charge, -1, NULL,
	ai_charge, -2, NULL,
	ai_charge, -3, NULL
};
mmove_t infantry_move_attack1 = {FRAME_attak111, FRAME_attak115, infantry_frames_attack1, infantry_run};


void infantry_swing (edict_t *self)
{
	gi.sound (self, CHAN_WEAPON, sound_punch_swing, 1, ATTN_NORM, 0);
}

void infantry_smack (edict_t *self)
{
	int		damage = 100 + 20 * self->monsterinfo.level; // dmg: infantry_smack

	if (!G_EntExists(self->enemy))
		return;

	if (M_MeleeAttack(self, 96, damage, 200))
		gi.sound (self, CHAN_AUTO, sound_punch_hit, 1, ATTN_NORM, 0);
}

mframe_t infantry_frames_attack2 [] =
{
	ai_charge, 3, NULL,
	ai_charge, 6, NULL,
	ai_charge, 0, infantry_swing,
	ai_charge, 8, NULL,
	ai_charge, 5, NULL,
	ai_charge, 8, infantry_smack,
	ai_charge, 6, NULL,
	ai_charge, 3, NULL,
};
mmove_t infantry_move_attack2 = {FRAME_attak201, FRAME_attak208, infantry_frames_attack2, infantry_run};

void infantry_attack(edict_t *self)
{
	if (entdist (self, self->enemy) <= 64)
	{
		self->monsterinfo.currentmove = &infantry_move_attack2;// melee attack
		return;
	}

	// machinegun attack
	self->monsterinfo.currentmove = &infantry_move_attack1;
	self->monsterinfo.pausetime = level.time + (GetRandom(25, 50) * FRAMETIME);
	self->monsterinfo.attack_finished = self->monsterinfo.pausetime;

	if (!(self->monsterinfo.aiflags & AI_STAND_GROUND))
		self->monsterinfo.attack_finished += GetRandom(10, 20) * FRAMETIME;
}

void infantry_melee (edict_t *self)
{

}

/*QUAKED monster_infantry (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight
*/
void init_drone_infantry (edict_t *self)
{
	sound_pain1 = gi.soundindex ("infantry/infpain1.wav");
	sound_pain2 = gi.soundindex ("infantry/infpain2.wav");
	sound_die1 = gi.soundindex ("infantry/infdeth1.wav");
	sound_die2 = gi.soundindex ("infantry/infdeth2.wav");

	sound_gunshot = gi.soundindex ("infantry/infatck1.wav");
	sound_weapon_cock = gi.soundindex ("infantry/infatck3.wav");
	sound_punch_swing = gi.soundindex ("infantry/infatck2.wav");
	sound_punch_hit = gi.soundindex ("infantry/melee2.wav");
	
	sound_sight = gi.soundindex ("infantry/infsght1.wav");
	sound_search = gi.soundindex ("infantry/infsrch1.wav");
	sound_idle = gi.soundindex ("infantry/infidle1.wav");

	self->s.modelindex = gi.modelindex("models/monsters/infantry/tris.md2");
	VectorSet (self->mins, -16, -16, -24);
	VectorSet (self->maxs, 16, 16, 32);
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;

	self->mass = 400;

	//don't override previous mtype
	if (!self->mtype)
		self->mtype = M_ENFORCER;	

	self->monsterinfo.control_cost = M_ENFORCER_CONTROL_COST;
	self->monsterinfo.cost = M_ENFORCER_COST;

	// set health
	self->health = M_ENFORCER_INITIAL_HEALTH+M_ENFORCER_ADDON_HEALTH*self->monsterinfo.level; // hlt: enforcer
	self->max_health = self->health;
	self->gib_health = -1.5 * BASE_GIB_HEALTH;

	// set armor
	self->monsterinfo.power_armor_type = POWER_ARMOR_SHIELD;
	self->monsterinfo.power_armor_power = M_ENFORCER_INITIAL_ARMOR+M_ENFORCER_ADDON_ARMOR*self->monsterinfo.level; // pow: soldier
	self->monsterinfo.max_armor = self->monsterinfo.power_armor_power;

	// jump and movement
	self->monsterinfo.jumpup = 64;
	self->monsterinfo.jumpdn = 512;
	self->monsterinfo.aiflags |= AI_NO_CIRCLE_STRAFE;

	self->item = FindItemByClassname("ammo_bullets");

	//self->pain = infantry_pain;
	self->die = infantry_die;

	self->monsterinfo.stand = infantry_stand;
	self->monsterinfo.walk = infantry_walk;
	self->monsterinfo.run = infantry_run;
	self->monsterinfo.attack = infantry_attack;
	self->monsterinfo.sight = infantry_sight;
	//self->monsterinfo.idle = infantry_fidget;
	self->monsterinfo.melee = infantry_melee;

	gi.linkentity (self);

	self->monsterinfo.currentmove = &infantry_move_stand;
	self->monsterinfo.scale = MODEL_SCALE;
}
