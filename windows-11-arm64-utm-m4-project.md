# Windows 11 ARM64 VM on an M4 MacBook — Project Log

> **Status:** Paused / continuing later  
> **Purpose:** Semester-long VM experimentation and Windows compatibility lab  
> **Host:** Apple Silicon M4 MacBook  
> **Hypervisor:** UTM 4.7.5  
> **Last updated:** 2026-09-03

---

## 1. Project Goal

The goal of this project is to experiment with Windows virtual machines on an M4 MacBook during the semester, while keeping the Windows environment isolated, lean, and useful for software that is not available or practical on macOS/Linux.

The original practical target included professional/audio-related software such as:

- EASE Focus 3
- Shure Wireless Workbench
- REAPER

The VM is **not intended to be a primary daily operating system**. The intent is to start Windows only when required.

A major constraint is storage: the Mac has limited internal storage, so the VM should remain as lean as reasonably possible.

---

## 2. Important Architecture Finding

The original setup reference/video described a conventional x64 Windows PC workflow using:

- Windows 11 IoT Enterprise LTSC
- Rufus
- Windows-To-Go
- x64/AMD64 boot
- BIOS/UEFI boot

That workflow does **not** directly apply to an M4 Mac.

The M4 is Apple Silicon/ARM64, so the correct Windows guest architecture is **ARM64/aarch64**.

For an Apple Silicon Mac, UTM should use virtualization with a matching ARM64 guest architecture rather than emulating x64 Windows.

---

## 3. UTM Version

UTM **4.7.5** was used.

This was intentionally kept on the stable release rather than moving to the 5.x beta.

---

## 4. First Windows Attempt — IoT Enterprise LTSC

### ISO

The first ISO downloaded was Microsoft's official:

`26100.1742.240906-0331.ge_release_svc_refresh_CLIENT_IOT_LTSC_EVAL_A64FRE_en-us.iso`

Approximate size:

`5.04 GB`

This was the **Windows 11 IoT Enterprise LTSC 2024 Evaluation ARM64** image.

### Why IoT LTSC was considered

The attraction was:

- Long-term servicing
- Less consumer-oriented Windows environment
- Fewer unnecessary components/apps
- Suitable for fixed-purpose use
- ARM64 availability
- Better fit for an isolated specialist VM

However, an important licensing/setup issue was encountered.

### Product-key problem

Windows Setup displayed:

> `Setup has failed to validate the product key`

The IoT Enterprise LTSC evaluation media has special evaluation licensing/SKU behavior. It is not equivalent to a normal retail Windows ISO where a generic "I don't have a product key" path can simply be assumed to work.

Microsoft's production IoT Enterprise licensing is also different from ordinary retail Windows licensing.

**Decision:** Do not attempt third-party activation, random keys, activation scripts, or licensing bypasses.

Instead, switch to the official Windows 11 ARM64 multi-edition ISO.

---

## 5. Working Windows Installation

The official Microsoft Windows 11 ARM64 ISO used for the successful installation was:

`Win11_25H2_English_Arm64_v2.iso`

Approximate size:

`7.4 GB`

Edition selected:

**Windows 11 Pro**

Configuration:

- Architecture: ARM64
- RAM: 8 GB
- CPU: 4 cores
- Virtual disk: approximately 64 GB
- Local Windows account: `ranger`

### Windows version

The successful installation reported:

- Edition: Windows 11 Pro
- Version: 25H2
- Installed: 2026-09-02
- OS build: 26200.8037
- Experience: Windows Feature Experience Pack 1000.26100.300.0
- System type: 64-bit operating system, ARM-based processor

Device name:

`WIN-MPBF28NB3BG`

Processor shown by Windows:

`virt-10.0 (1.00 GHz)`

---

## 6. UTM VM Configuration

The VM was created using UTM/QEMU with virtualization enabled.

Configuration used:

- Engine: QEMU
- Virtualization: enabled
- Architecture: ARM64 / aarch64
- Machine: QEMU 10.0 ARM Virtual Machine
- RAM: 8 GB
- CPU: 4 cores
- Storage: approximately 64 GB virtual NVMe disk

The Windows ISO was initially attached as a virtual CD/DVD drive.

---

## 7. ARM64 UEFI Boot Issue and Resolution

On the first IoT installation attempt, UTM booted to the:

`UEFI Interactive Shell`

The ISO was nevertheless readable.

The following path was used:

```text
fs0:
dir
cd EFI
cd BOOT
dir
```

The ARM64 bootloader was found:

```text
BOOTAA64.EFI
```

It was then launched manually:

```text
BOOTAA64.EFI
```

Windows Setup appeared and displayed:

> `Press any key to boot from CD or DVD......`

The first attempt missed the prompt and returned to the shell.

The successful method was to launch the ARM64 EFI bootloader again and press a key immediately when prompted.

This successfully entered Windows Setup.

---

## 8. Windows Installation

Windows Setup was completed using:

- English (United States)
- Windows 11 Pro
- Custom installation
- The VM's virtual disk

After installation, the VM rebooted.

### Important boot behavior

The Windows installer ISO initially remained attached.

After the reboot, UTM booted the installer again, which looked like the installation had restarted.

The correct behavior is:

- Do **not** press a key if Windows displays:
  `Press any key to boot from CD or DVD...`
- Let the countdown expire so the VM boots from the installed virtual disk.

After confirming the installation, the Windows installer ISO was detached.

---

## 9. UTM Guest Tools

The UTM Guest Tools ISO was already available in the VM configuration:

`utm-guest-tools-latest.iso`

The tools were installed in Windows.

The Windows installer ISO was subsequently removed from the VM's virtual CD/DVD drive.

The guest-tools ISO was kept attached temporarily.

Guest Tools are intended to provide better integration/drivers such as SPICE support.

---

## 10. Exam Application Discovery

A major project constraint was discovered after Windows was working.

The application being tested is an **exam application** that explicitly does not support virtual machines.

The user confirmed:

> "it's an exam application, so it doesn't support VMs in any kind. That is the end of the path."

Therefore:

**Do not attempt to bypass or defeat VM detection for the exam software.**

The VM project itself can continue, but the prohibited exam application should be run on supported physical hardware instead.

---

## 11. Current VM State

At the time this project was paused:

### Host

- MacBook with Apple M4
- macOS host
- Limited internal storage

### Guest

- Windows 11 Pro
- 25H2
- ARM64
- 8 GB RAM
- 4 virtual CPU cores
- ~64 GB virtual disk
- Local account `ranger`
- UTM Guest Tools installed
- Windows installer ISO detached

### Current purpose

The VM is now a working Windows ARM64 laboratory environment.

The original exam-application objective is abandoned because the application prohibits VMs.

---

## 12. Things NOT to Do

### Do not:

- Use x64 Windows as the guest on the M4 unless there is a specific reason to emulate it.
- Use random Windows activation keys.
- Use third-party activation scripts.
- Bypass licensing restrictions.
- Attempt to defeat an exam application's VM detection.
- Delete Windows system files blindly.
- Aggressively debloat Windows before identifying dependencies.
- Remove drivers needed for USB/audio/network functionality.
- Delete the VM's virtual disk when changing ISO files.

---

## 13. Planned Next Work

This is intentionally postponed.

When continuing the project, investigate:

### A. Measure the VM first

Record:

- Idle RAM usage
- Disk usage
- CPU usage
- Boot time
- Virtual disk growth
- Windows background services

### B. Safe Windows cleanup

Remove only unnecessary components after checking dependencies.

Potential areas:

- Unused consumer apps
- Startup programs
- Optional Windows features
- Unused language packs
- Temporary files
- Windows update leftovers where safe

Keep compatibility with:

- REAPER
- Audio interfaces
- USB devices
- Network adapters
- Specialized Windows software

### C. UTM optimization

Experiment with:

- CPU allocation
- RAM allocation
- Display configuration
- SPICE
- USB passthrough
- Network mode
- Disk configuration
- Suspend vs shutdown
- Snapshot/backup strategy

### D. Audio workflow

Test:

- REAPER
- USB audio interface passthrough
- ASIO drivers where supported
- Low-latency audio
- MIDI/USB devices
- Network audio/control software

### E. Windows ARM compatibility

Document which x86/x64 applications work through Windows ARM emulation and which do not.

Maintain a compatibility table:

| Application | Architecture | Works on ARM64 VM? | Notes |
|---|---|---:|---|
| REAPER | TBD | TBD | Test later |
| EASE Focus 3 | TBD | TBD | Test later if appropriate |
| Shure Wireless Workbench | TBD | TBD | Test later if appropriate |
| Exam application | TBD | **No — VM prohibited** | Use physical supported machine |

---

## 14. Lessons Learned

1. **Architecture matters.** An M4 Mac is ARM64, so an ARM64 Windows guest is the natural choice.
2. **The x64 Windows-To-Go/Rufus workflow from a conventional PC video should not be copied directly to Apple Silicon.**
3. **Windows 11 IoT Enterprise LTSC evaluation media is not the same as ordinary retail Windows media.** Evaluation/production licensing and setup behavior must be treated separately.
4. **UTM can successfully virtualize Windows 11 ARM64 on Apple Silicon.**
5. **The ARM64 EFI loader is `BOOTAA64.EFI`.**
6. **Leaving the installer ISO attached can cause the VM to boot back into Windows Setup after installation.**
7. **A VM is not suitable for software that explicitly prohibits virtual machines, especially exam/proctoring software.**
8. **The best approach for this semester-long project is incremental experimentation rather than aggressive system modification.**

---

## 15. Project Philosophy

The VM should be treated as a **controlled Windows laboratory** rather than a permanent replacement for macOS.

Goals:

> **Small → Fast → Reproducible → Compatible → Documented**

Every optimization should be reversible or documented.

When experimenting with Windows internals, keep a known-good baseline VM or backup before making major changes.

---

## 16. Future Documentation

As experiments continue, add sections for:

- VM configuration benchmarks
- Windows optimization experiments
- Application compatibility results
- USB passthrough tests
- Audio latency measurements
- Network performance
- Disk usage over time
- Snapshot/backup strategy
- UTM configuration changes
- Problems encountered and fixes
- Reproducible setup procedure

This file is intended to become the project's long-term technical log and README/reference for rebuilding the environment.
