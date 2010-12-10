//Properties of additions
, {"FPLT",	PIXPACK(0x00FF00),	0.0f,	0.00f * CFDS,	0.95f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	20,		0,	0,	10,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	65,		"Fast Growing Plant. Grows around particles."								, TYPE_SOLID},
{"SOAP",	PIXPACK(0xFFFFFF),	0.6f,	0.01f * CFDS,	0.98f,	0.95f,	0.0f,	0.1f,	0.00f,	0.000f	* CFDS,	2,	0,		0,	0,	20,	1,	40,		SC_ADD,		R_TEMP-2.0f	+273.15f,	29,		"Soap, Basic. Removes Powders, Liquids, and Gases. Neutralizes Acid."		, TYPE_LIQUID},
{"REMT",	PIXPACK(0x808080),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Radio Wave Emitter. Transfers signals to Radio Wave Receivers."			, TYPE_SOLID | PROP_CONDUCTS},
{"RREC",	PIXPACK(0xA0A0A0),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Radio Wave Receiver. Gets signals from Radio Wave Emitters."			    , TYPE_SOLID | PROP_CONDUCTS},
{"CHAN",	PIXPACK(0x000000),	0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.0f,	0.0f,	0.0f,	0.000f  * CFDS,	0,	0,		0,	0,	0,	1,	-1,		SC_ADD,	    R_TEMP+0.0f +273.15f,	60,		"Channel Changer. Changes channel of radio communications."              	, TYPE_ENERGY},
{"PROT",	PIXPACK(0xDDDD00),	0.2f,	0.00f * CFDS,	1.00f,	1.00f,	-0.99f,	0.0f,	0.20f,	0.002f	* CFDS,	0,	0,		0,	0,	0,	1,	-1,		SC_ADD,		R_TEMP+4.0f	+273.15f,	60,		"Protons. Changes elements to the next one in the element table."			, TYPE_ENERGY},
{"WAVE",	PIXPACK(0x000000),	0.2f,	0.00f * CFDS,	1.00f,	1.00f,	0.0f,	0.0f,	0.2f,	0.000f  * CFDS,	0,	0,		0,	0,	0,	1,	-1,		SC_ADD,		R_TEMP+0.0f +273.15f,	60,		"Radio Waves. Signals that are floating freely and happily."				, TYPE_ENERGY},
{"WAVE",	PIXPACK(0x000000),	0.2f,	0.00f * CFDS,	1.00f,	1.00f,	0.0f,	0.0f,	0.1f,	0.000f  * CFDS,	0,	0,		0,	0,	0,	0,	-1,		SC_ADD,	    R_TEMP+0.0f +273.15f,	60,		"Radio Waves from Emitters. Signals that are floating freely and happily."	, TYPE_ENERGY},
{"INTF",	PIXPACK(0xF0F0F0),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Interfering Object. Blocks Emitters from emitting into its other side."	, TYPE_SOLID},
{"WEMT",	PIXPACK(0xA0A0A0),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Wired Emitter. Transfers signals to any Wired Receiver."					, TYPE_SOLID | PROP_CONDUCTS},
{"WREC",	PIXPACK(0xD0D0D0),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Wired Receiver. Gets signals from any Wired Emitter."						, TYPE_SOLID | PROP_CONDUCTS},
{"PGLW",	PIXPACK(0x63AD5F),	0.7f,	0.02f * CFDS,	0.96f,	0.80f,	0.0f,	0.1f,	0.00f,	0.000f	* CFDS,	1,	0,		0,	0,	30,	1,	70,		SC_ADD,		R_TEMP+0.0f	+273.15f,	70,		"Glow Powder. Mix to water to become GLOW."									, TYPE_PART},
{"IEMT",	PIXPACK(0x808080),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Infrared Emitter. Transfers signals to any Infrared Receiver."			    , TYPE_SOLID | PROP_CONDUCTS},
{"IREC",	PIXPACK(0xA0A0A0),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Infrared Receiver. Gets signals from any Infrared Emitter."			    , TYPE_SOLID | PROP_CONDUCTS},
{"IWVE",	PIXPACK(0x000000),	0.2f,	0.00f * CFDS,	1.00f,	1.00f,	1.0f,	0.0f,	0.2f,	0.000f  * CFDS,	0,	0,		0,	0,	0,	0,	-1,		SC_ADD,	    R_TEMP+0.0f +273.15f,	60,		"Infrared. Signals that are lining up in a strict manner."	                , TYPE_ENERGY},
{"HGEN",	PIXPACK(0x808080),	0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.0f,	0.0f,	0.00f,	0.000f	* CFDS,	0,	0,		0,	1,	1,	1,	100,	SC_ADD,		R_TEMP+0.0f	+273.15f,	251,	"Heat Generator. Generates circular heat waves."            			    , TYPE_SOLID},
{"HWVE",	PIXPACK(0x000000),	0.3f,	0.00f * CFDS,	1.00f,	1.00f,	0.0f,	0.0f,	0.3f,	0.000f  * CFDS,	0,	0,		0,	0,	0,	1,	-1,		SC_ADD,		    1000.0f +273.15f,	60,		"Heat Waves. Heats surrounding particles."                  				, TYPE_ENERGY},
//Name		Colour				Advec	Airdrag			Airloss	Loss	Collid	Grav	Diffus	Hotair			Fal	Burn	Exp	Mel	Hrd	M	Weights	Section			H						Ins(real world, by triclops200)		Description										Properties

//Name			- 4 letter name of the element
//Color			- self-descriptive
//Advec			- spreadibility (<= 1.0f)
//Airdrag		- how air slows it down
//Airloss		- how much air makes when falling
//Loss			- how much velocity it loses (delta v factor, 0 means none 0.5 means half)
//Collid		- unknown?
//Grav			- how much gravity affects it
//Diffus		- how much it spreads
//Hotair		- how much it heats the surroundings
//Fal			- 0 - Solids and Gases 1 - Powders 2 - Liquids
//Burn			- how much it burns
//Exp			- pressure created when it explodes
//mel			- meltability
//hrd			- ability for it to be affected by acid (higher number -> higher effectivity)
//M				- does it appear in the menu
//Weights		- relative weight of object (higher means it falls through)
//Section		- where it will be put in the menu
//H				- initial temperature
//Ins			- real life heat value
//Description	- already descriptive
//Properties	- additional properties
//TYPE_PART				Powders
//TYPE_LIQUID			Liquids
//TYPE_SOLID			Solids
//TYPE_GAS				Gasses (Includes plasma)
//TYPE_ENERGY			Energy (Thunder, Light, Neutrons etc.)
//PROP_CONDUCTS			Conducts electricity (Currently Unused)
//PROP_BLACK			Absorbs Photons
//PROP_NEUTPENETRATE	Penetrated by neutrons
//PROP_NEUTABSORB		Absorbs neutrons, reflect is default
//PROP_NEUTPASS			Neutrons pass through, such as with glass
//PROP_DEADLY			Is deadly for stickman.
