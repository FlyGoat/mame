// license:BSD-3-Clause
// copyright-holders:Wilbert Pol
/*****************************************************************************
 *
 * MSX Floopy drive interface add-on cartridges
 *
 * Currently supported:
 * - National FS-CF351 + FS-FD351 - MB8877A - DSDD 3.5" Floppy drive + interface
 * - Panasonic FS-FD1 - WD2793? - DSDD 3.5" Floppy drive + interface
 * - Panasonic FS-FD1A - TC8566F - DSDD 3.5" Floppy drive with builtin interface
 *                     - Rom label reads: "FDC BIOS V1.0 / COPYRIGHT MEI / 1987 DASFD1AA1"
 * - Philips VY-0010 (Interface cartridge + 1 3.5" SS floppy drive)
 *
 * Not supported yet:
 * - Canon VF-100 - DSDD 3.5" Floppy drive + interface + 1 floppy disk containing MSX-DOS
 * - Talent DPF-550/5 - WD1772 - DSDD 5.25" Floppy drive (360KB) plus interface (manufactured by Daewoo)
 *                    - Rom label markings: MSX DISK / DPF 555D
 *
 * Drive only:
 * - Philps VY-0011 - 3.5" SSDD Floppy drive
 * - Talent DPF-560 - DSDD 5.25" Floppy drive
 *
 * To be investigated:
 * - AVT DPF-500 - WD1772? - DD 5.25" Floppy drive + interface + 1 floppy disk containing MSX-DOS
 * - Daewoo CPF-350C - DD 3.5" Floppy drive
 * - Daewoo CPF-360C - DD 3.5" Floppy drive
 * - Daewoo MPF-550 - DSDD 5.25" Floppy drive + interface
 * = Daewoo MPF-560 - DSDD 5.25" Floppy drive
 * - DMX Interface para drive - Interface + 1 floppy disk containg MSX-DOS 1.0
 * - Fenner FD-300 - DSDD 3.5" Floppy drive
 * - Fenner FD-400 - Floppy interface for FD-300
 * - Hitachi MPF-310CH - DSDD Floppy drive
 * - hitachi MPC-310CH - Interface for MPF-310CH
 * - JVC HC-F303 - Floppy drive
 * - Mitsubishi ML-30FD - DSDD 3.5" Floppy drive
 * - Mitsubishi ML-30DC - Floppy interface
 * - Philips NMS-1200 - Floppy interface
 * - Philips NMS-9111 - 3.5" Floppy drive
 * - Philips NMS-9113 - 3.5" Floppy drive
 * - Sakir AFD-01 - SSDD 3.5" Floppy drive
 * - Sanyo MFD-001 - 360KB 5.25" Floppy drive + interface?
 * - Sanyo MFD-002 - 360KB 5.25" Floppy drive (2nd drive for MFD-001?)
 * - Sanyo MFD-25FD - DSDD 3.5" Floppy drive
 * - Sanyo MFD-35 - SSDD 3.5" Floppy drive + interface
 * - Sharp Epcom HB-3600 - WD2793 - Floppy interface Intended to be used with HB-6000 (5.25" SS? drive), Brazil
 *                       - Sold as part of HB-3600 + HB-6000 bundle according to wikipedia
 * - Sharp Epcom HB-6000 - 360KB 5.25" drive
 * - Sony HBD-100 - SSDD 3.5" Floppy drivbe
 * - Sony HBD-20W - DSDD 3.5" Floppy drive
 * - Sony HBD-30X/30W - DSDD 3.5" drive
 * - Sony HBD-50 - SSDD 3.5" drive (drive only?)
 * - Sony HBD-F1 (interface only?) - WD2793 - 3.5" DSDD drive??
 * - Sony HBX-30 (interface only, meant for 30W) - WD2793
 * - Sony WS2793-02 - WD2793? - Interface for HBD-50
 * - Spectravideo SVI-213 - MB8877A - Floppy interface for SVI-707
 * - Spectravideo SVI-707 - MB8877A - 5.25" SSDD? drive (320KB) - There seem to be 2 ROMs on the PCB, apparently one is for MSX and one is for CP/M operation?
 *                        - See https://plus.google.com/photos/115644813183575095400/albums/5223347091895442113?banner=pwa
 * - Spectravideo SVI-717 - Interface for 2 drives?
 * - Spectravideo SVI-787 - SSDD 3.5" Floppy drive
 * - Spectravideo SVI-801 - Interface
 * - Toshiba HX-F100 - Floppy drive
 * - Toshiba HX-F101 - SSDD 3.5" Floppy drive + interface
 * - Yamaha FD-01 - SSDD 3.5" Floppy drive
 * - Yamaha FD-03 - DSDD 3.5" Floppy drive
 * - Yamaha FD-05 - DSDD 3.5" Floppy drive
 * - Other models:
 *   - ACVS 3.5" Floppy drive interface
 *   - Tradeco floppy interface
 *   - Angeisa 3.5" Floppy drive
 *   - Angeisa 5.25" 360KB Floppy drive
 *   - Angeisa 5.25" 720KB Floppy drive
 *   - Angeisa floppy drive interface
 *   - Datagame floppy drive interface
 *   - Digital Design DSDD 3.5" Floppy drive
 *   - Digital Design 5.25" 360KB Floppy drive
 *   - Digital Design 5.25" 720KB Floppy drive
 *   - Digital Design floppy drive interface
 *   - DMX 3.5" Floppy drive
 *   - DMX floppy drive interface
 *   - Liftron 3.5" Floppy drive
 *   - Liftron floppy drive interface
 *   - Microsol DRX-180 5.25" Floppy drive FS
 *   - Microsol DRX-360 5.25" Floppy drive FD
 *   - Microsol DRX-720 5.25" Floppy drive 80 track (720KB)
 *   - Microsol CDX-1 floppy interface
 *   - Microsol CDX-2 floppy interface
 *   - Racidata 3.5" Floppy drive
 *   - Racidata 5.25" Floppy drive
 *   - Racidata floppy interface
 *   - Sileman Triton-s 3.5" FS Floppy drive
 *   - Sileman Triton-d 3.5" FD Floppy drive
 *   - Talent TPF-723 5.25" Floppy drive
 *   - Talent TPF-725 5.25" Flpppy drive
 *   - Technohead Leopard 3.5" Floppy drive
 *   - Technohead Leopard 5.25" Floppy drive
 *   - Technohead floppy interface
 * - More??
 *
 * Several model references found in Vitropedia (ISBN 9781409212774)
 *
 ****************************************************************************/

#include "emu.h"
#include "disk.h"
#include "formats/dmk_dsk.h"
#include "formats/msx_dsk.h"
#include "softlist_dev.h"

DEFINE_DEVICE_TYPE(MSX_CART_VY0010,  msx_cart_vy0010_device,  "msx_cart_vy0010",  "MSX Cartridge - VY0010")
DEFINE_DEVICE_TYPE(MSX_CART_FSFD1,   msx_cart_fsfd1_device,   "msx_cart_fsfd1",   "MSX Cartridge - FS-FD1")
DEFINE_DEVICE_TYPE(MSX_CART_FSFD1A,  msx_cart_fsfd1a_device,  "msx_cart_fsfd1a",  "MSX Cartridge - FS-FD1A")
DEFINE_DEVICE_TYPE(MSX_CART_FSCF351, msx_cart_fscf351_device, "msx_cart_fscf351", "MSX Cartridge - FS-CF351")


void msx_cart_disk_device::floppy_formats(format_registration &fr)
{
	fr.add_mfm_containers();
	fr.add(FLOPPY_MSX_FORMAT);
	fr.add(FLOPPY_DMK_FORMAT);
}


static void msx_floppies(device_slot_interface &device)
{
	device.option_add("35dd", FLOPPY_35_DD);
	device.option_add("35ssdd", FLOPPY_35_SSDD);
}


msx_cart_disk_device::msx_cart_disk_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, u32 clock)
	: device_t(mconfig, type, tag, owner, clock)
	, msx_cart_interface(mconfig, *this)
	, m_floppy0(*this, "fdc:0")
	, m_floppy1(*this, "fdc:1")
	, m_floppy(nullptr)
{
}


msx_cart_disk_wd_device::msx_cart_disk_wd_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_device(mconfig, type, tag, owner, clock)
	, m_fdc(*this, "fdc")
{
}


msx_cart_disk_type1_device::msx_cart_disk_type1_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_wd_device(mconfig, type, tag, owner, clock)
	, m_led(*this, "led0")
	, m_side_control(0)
	, m_control(0)
{
}


msx_cart_disk_type2_device::msx_cart_disk_type2_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_wd_device(mconfig, type, tag, owner, clock)
	, m_led(*this, "led0")
	, m_control(0)
{
}


msx_cart_vy0010_device::msx_cart_vy0010_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_type1_device(mconfig, MSX_CART_VY0010, tag, owner, clock)
{
}


msx_cart_fsfd1_device::msx_cart_fsfd1_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_type1_device(mconfig, MSX_CART_FSFD1, tag, owner, clock)
{
}


msx_cart_fscf351_device::msx_cart_fscf351_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_type2_device(mconfig, MSX_CART_FSCF351, tag, owner, clock)
{
}


msx_cart_disk_tc8566_device::msx_cart_disk_tc8566_device(const machine_config &mconfig, device_type type, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_device(mconfig, type, tag, owner, clock)
	, m_fdc(*this, "fdc")
{
}


msx_cart_fsfd1a_device::msx_cart_fsfd1a_device(const machine_config &mconfig, const char *tag, device_t *owner, u32 clock)
	: msx_cart_disk_tc8566_device(mconfig, MSX_CART_FSFD1A, tag, owner, clock)
{
}


void msx_cart_disk_device::initialize_cartridge()
{
	if (get_rom_size() != 0x4000)
	{
		fatalerror("msx_cart_disk_device: Invalid ROM size\n");
	}
}


void msx_cart_vy0010_device::device_add_mconfig(machine_config &config)
{
	// From VY-0010 schematic:
	// HLT pulled high
	// SSO/-ENMF + -DDEN + ENP + -5/8 - pulled low
	// READY inverted in VY-0010 cartridge and pulled low on VY-0010/VY-0011 floppy drive
	WD2793(config, m_fdc, 4_MHz_XTAL / 4);
	m_fdc->set_force_ready(true);

	// Single sided 3.5" floppy drive
	FLOPPY_CONNECTOR(config, "fdc:0", msx_floppies, "35ssdd", msx_cart_disk_device::floppy_formats);

	// Attach software lists
	// We do not know in what kind of machine the user has inserted the floppy interface
	// so we list all msx floppy software lists.
	//
	SOFTWARE_LIST(config, "flop_list").set_original("msx2_flop");
	SOFTWARE_LIST(config, "msx1_flop_list").set_compatible("msx1_flop");
}


void msx_cart_fsfd1_device::device_add_mconfig(machine_config &config)
{
	WD2793(config, m_fdc, 4_MHz_XTAL / 4);

	// Double sided 3.5" floppy drive
	FLOPPY_CONNECTOR(config, "fdc:0", msx_floppies, "35dd", msx_cart_disk_device::floppy_formats);

	// Attach software lists
	// We do not know in what kind of machine the user has inserted the floppy interface
	// so we list all msx floppy software lists.
	//
	SOFTWARE_LIST(config, "flop_list").set_original("msx2_flop");
	SOFTWARE_LIST(config, "msx1_flop_list").set_compatible("msx1_flop");
}


void msx_cart_fsfd1a_device::device_add_mconfig(machine_config &config)
{
	TC8566AF(config, m_fdc, 16'000'000);

	// Double sided 3.5" floppy drive
	FLOPPY_CONNECTOR(config, "fdc:0", msx_floppies, "35dd", msx_cart_disk_device::floppy_formats);

	// Attach software lists
	// We do not know in what kind of machine the user has inserted the floppy interface
	// so we list all msx floppy software lists.
	//
	SOFTWARE_LIST(config, "flop_list").set_original("msx2_flop");
	SOFTWARE_LIST(config, "msx1_flop_list").set_compatible("msx1_flop");
}


void msx_cart_fscf351_device::device_add_mconfig(machine_config &config)
{
	MB8877(config, m_fdc, 4_MHz_XTAL / 4);
	m_fdc->set_force_ready(true);

	// Double sided 3.5" floppy drive
	FLOPPY_CONNECTOR(config, "fdc:0", msx_floppies, "35dd", msx_cart_disk_device::floppy_formats);

	// Attach software lists
	// We do not know in what kind of machine the user has inserted the floppy interface
	// so we list all msx floppy software lists.
	//
	SOFTWARE_LIST(config, "flop_list").set_original("msx2_flop");
	SOFTWARE_LIST(config, "msx1_flop_list").set_compatible("msx1_flop");
}


void msx_cart_disk_type1_device::device_start()
{
	m_led.resolve();

	save_item(NAME(m_side_control));
	save_item(NAME(m_control));
}

void msx_cart_disk_type1_device::initialize_cartridge()
{
	msx_cart_disk_wd_device::initialize_cartridge();

	page(1)->install_rom(0x4000, 0x7fff, get_rom_base());
	page(1)->install_read_handler(0x7ff8, 0x7ff8, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::status_r)));
	page(1)->install_read_handler(0x7ff9, 0x7ff9, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_r)));
	page(1)->install_read_handler(0x7ffa, 0x7ffa, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_r)));
	page(1)->install_read_handler(0x7ffb, 0x7ffb, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_r)));
	page(1)->install_read_handler(0x7ffc, 0x7ffc, read8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::side_control_r)));
	page(1)->install_read_handler(0x7ffd, 0x7ffd, read8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::control_r)));
	page(1)->install_read_handler(0x7fff, 0x7fff, read8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::status_r)));
	page(1)->install_write_handler(0x7ff8, 0x7ff8, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::cmd_w)));
	page(1)->install_write_handler(0x7ff9, 0x7ff9, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_w)));
	page(1)->install_write_handler(0x7ffa, 0x7ffa, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_w)));
	page(1)->install_write_handler(0x7ffb, 0x7ffb, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_w)));
	page(1)->install_write_handler(0x7ffc, 0x7ffc, write8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::set_side_control)));
	page(1)->install_write_handler(0x7ffd, 0x7ffd, write8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::set_control)));

	// TODO No idea why, but without this the other handlers do not get recognized
	page(2)->install_rom(0xbff8,0xbff8, get_rom_base());
	page(2)->install_read_handler(0xbff8, 0xbff8, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::status_r)));
	page(2)->install_read_handler(0xbff9, 0xbff9, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_r)));
	page(2)->install_read_handler(0xbffa, 0xbffa, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_r)));
	page(2)->install_read_handler(0xbffb, 0xbffb, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_r)));
	page(2)->install_read_handler(0xbffc, 0xbffc, read8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::side_control_r)));
	page(2)->install_read_handler(0xbffd, 0xbffd, read8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::control_r)));
	page(2)->install_read_handler(0xbfff, 0xbfff, read8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::status_r)));
	page(2)->install_write_handler(0xbff8, 0xbff8, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::cmd_w)));
	page(2)->install_write_handler(0xbff9, 0xbff9, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_w)));
	page(2)->install_write_handler(0xbffa, 0xbffa, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_w)));
	page(2)->install_write_handler(0xbffb, 0xbffb, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_w)));
	page(2)->install_write_handler(0xbffc, 0xbffc, write8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::set_side_control)));
	page(2)->install_write_handler(0xbffd, 0xbffd, write8smo_delegate(*this, FUNC(msx_cart_disk_type1_device::set_control)));
}

void msx_cart_disk_type1_device::device_post_load()
{
	uint8_t data = m_control;

	// To make sure the FDD busy led status gets set correctly
	m_control ^= 0x40;

	set_control(data);
}

void msx_cart_disk_type1_device::set_control(uint8_t data)
{
	uint8_t old_m_control = m_control;

	m_control = data;

	switch (m_control & 0x03)
	{
		case 0:
		case 2:
			m_floppy = m_floppy0 ? m_floppy0->get_device() : nullptr;
			break;

		case 1:
			m_floppy = m_floppy1 ? m_floppy1->get_device() : nullptr;
			break;

		default:
			m_floppy = nullptr;
			break;
	}

	if (m_floppy)
	{
		m_floppy->mon_w((m_control & 0x80) ? 0 : 1);
		m_floppy->ss_w(m_side_control & 0x01);
	}

	m_fdc->set_floppy(m_floppy);

	if ((old_m_control ^ m_control) & 0x40)
	{
		m_led = BIT(~m_control, 6);
	}
}

void msx_cart_disk_type1_device::set_side_control(uint8_t data)
{
	m_side_control = data;

	if (m_floppy)
	{
		m_floppy->ss_w(m_side_control & 0x01);
	}
}

void msx_cart_disk_type1_device::device_reset()
{
	m_fdc->dden_w(false);
}

u8 msx_cart_disk_type1_device::side_control_r()
{
	return 0xfe | (m_side_control & 0x01);
}

u8 msx_cart_disk_type1_device::control_r()
{
	return ( m_control & 0x83 ) | 0x78;
}

u8 msx_cart_disk_type1_device::status_r()
{
	return 0x3f | (m_fdc->intrq_r() ? 0 : 0x40) | (m_fdc->drq_r() ? 0 : 0x80);
}



void msx_cart_disk_type2_device::device_start()
{
	m_led.resolve();

	save_item(NAME(m_control));
}

void msx_cart_disk_type2_device::device_reset()
{
	m_fdc->dden_w(false);
}

void msx_cart_disk_type2_device::device_post_load()
{
	uint8_t data = m_control;

	// To make sure the FDD busy led status gets set correctly
	m_control ^= 0x40;

	set_control(data);
}

void msx_cart_disk_type2_device::initialize_cartridge()
{
	msx_cart_disk_wd_device::initialize_cartridge();

	page(1)->install_rom(0x4000, 0x7fff, get_rom_base());
	page(1)->install_read_handler(0x7fb8, 0x7fb8, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::status_r)));
	page(1)->install_read_handler(0x7fb9, 0x7fb9, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_r)));
	page(1)->install_read_handler(0x7fba, 0x7fba, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_r)));
	page(1)->install_read_handler(0x7fbb, 0x7fbb, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_r)));
	page(1)->install_read_handler(0x7fbc, 0x7fbc, read8smo_delegate(*this, FUNC(msx_cart_disk_type2_device::status_r)));
	page(1)->install_write_handler(0x7fb8, 0x7fb8, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::cmd_w)));
	page(1)->install_write_handler(0x7fb9, 0x7fb9, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_w)));
	page(1)->install_write_handler(0x7fba, 0x7fba, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_w)));
	page(1)->install_write_handler(0x7fbb, 0x7fbb, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_w)));
	page(1)->install_write_handler(0x7fbc, 0x7fbc, write8smo_delegate(*this, FUNC(msx_cart_disk_type2_device::set_control)));

	// TODO No idea why, but without this the other handlers do not get recognized
	page(2)->install_rom(0xbfb8,0xbfb8, get_rom_base());
	page(2)->install_read_handler(0xbfb8, 0xbfb8, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::status_r)));
	page(2)->install_read_handler(0xbfb9, 0xbfb9, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_r)));
	page(2)->install_read_handler(0xbfba, 0xbfba, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_r)));
	page(2)->install_read_handler(0xbfbb, 0xbfbb, read8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_r)));
	page(2)->install_read_handler(0xbfbc, 0xbfbc, read8smo_delegate(*this, FUNC(msx_cart_disk_type2_device::status_r)));
	page(2)->install_write_handler(0xbfb8, 0xbfb8, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::cmd_w)));
	page(2)->install_write_handler(0xbfb9, 0xbfb9, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::track_w)));
	page(2)->install_write_handler(0xbfba, 0xbfba, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::sector_w)));
	page(2)->install_write_handler(0xbfbb, 0xbfbb, write8smo_delegate(*m_fdc, FUNC(wd_fdc_analog_device_base::data_w)));
	page(2)->install_write_handler(0xbfbc, 0xbfbc, write8smo_delegate(*this, FUNC(msx_cart_disk_type2_device::set_control)));
}

void msx_cart_disk_type2_device::set_control(u8 data)
{
	uint8_t old_m_control = m_control;

	m_control = data;

	switch (m_control & 3)
	{
		case 1:
			m_floppy = m_floppy0 ? m_floppy0->get_device() : nullptr;
			break;

		case 2:
			m_floppy = m_floppy1 ? m_floppy1->get_device() : nullptr;
			break;

		default:
			m_floppy = nullptr;
			break;
	}

	if (m_floppy)
	{
		m_floppy->mon_w((m_control & 0x08) ? 0 : 1);
		m_floppy->ss_w((m_control & 0x04) ? 1 : 0);
	}

	m_fdc->set_floppy(m_floppy);

	if ((old_m_control ^ m_control) & 0x40)
	{
		m_led = BIT(~m_control, 6);
	}
}

u8 msx_cart_disk_type2_device::status_r()
{
	return 0x3f | (m_fdc->drq_r() ? 0 : 0x40) | (m_fdc->intrq_r() ? 0x80 : 0);
}




void msx_cart_fsfd1a_device::device_start()
{
}


void msx_cart_fsfd1a_device::device_reset()
{
}

void msx_cart_fsfd1a_device::initialize_cartridge()
{
	msx_cart_disk_tc8566_device::initialize_cartridge();

	page(1)->install_rom(0x4000, 0x7fff, get_rom_base());
	page(1)->install_read_handler(0x7ffa, 0x7ffa, read8smo_delegate(*m_fdc, FUNC(tc8566af_device::msr_r)));
	page(1)->install_read_handler(0x7ffb, 0x7ffb, read8smo_delegate(*m_fdc, FUNC(tc8566af_device::fifo_r)));
	page(1)->install_write_handler(0x7ff8, 0x7ff8, write8smo_delegate(*m_fdc, FUNC(tc8566af_device::dor_w)));
	page(1)->install_write_handler(0x7ff9, 0x7ff9, write8smo_delegate(*m_fdc, FUNC(tc8566af_device::cr1_w)));
	page(1)->install_write_handler(0x7ffb, 0x7ffb, write8smo_delegate(*m_fdc, FUNC(tc8566af_device::fifo_w)));
	// TODO No idea why, but without this the other handlers do not get recognized
	page(2)->install_rom(0xbffa,0xbffa, get_rom_base());
	page(2)->install_read_handler(0xbffa, 0xbffa, read8smo_delegate(*m_fdc, FUNC(tc8566af_device::msr_r)));
	page(2)->install_read_handler(0xbffb, 0xbffb, read8smo_delegate(*m_fdc, FUNC(tc8566af_device::fifo_r)));
	page(2)->install_write_handler(0xbff8, 0xbff8, write8smo_delegate(*m_fdc, FUNC(tc8566af_device::dor_w)));
	page(2)->install_write_handler(0xbff9, 0xbff9, write8smo_delegate(*m_fdc, FUNC(tc8566af_device::cr1_w)));
	page(2)->install_write_handler(0xbffb, 0xbffb, write8smo_delegate(*m_fdc, FUNC(tc8566af_device::fifo_w)));
}
