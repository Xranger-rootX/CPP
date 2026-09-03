Reading the remaining source-of-truth files (both ROADMAPs + register formats) so the brief is grounded, not from memory:# The complete brief — both research loops, origin to now

*Everything below is verified against git logs, both STATE.md files, both ROADMAPs, the live cron table (checked 23:18 IST, Thu 2026-09-03), and the session record. Nothing is from memory alone.*

---

## 1. What are we doing?

We are running **two autonomous, recurring research-paper production loops** inside Hermes, one per repo, that carry you from *literature collection* all the way to a *submission-ready survey paper* — with you reviewing rather than doing the heavy lifting.

| | **Loop 1** | **Loop 2** |
|---|---|---|
| Paper | *Serverless Cold-Start Mitigation: A Survey* | *Approximate-Membership & Probabilistic Data Structures: Recent Advances* |
| Course tie-in | CSE423 Virtualization & Cloud Computing | CSE205 DSA × MTH401 Discrete Math |
| The niche | Infra-centric survey of **2024–26** cold-start work: microVM platforms (Firecracker/Kata), snapshot/restore & fork, pooling & keep-alive, WASM runtimes, predictive scheduling, LLM-serving cold start | Survey of the **2024–26 window** in AMQ/probabilistic structures: parallel/hardware filters (Wormhole, PipeFilter), learned variants, **the fresh adversarial-robustness/DP thread**, cuckoo/sketching |
| Why it's defensible | The 2 big incumbent surveys (ACM CSUR 2024, Computing 2024) **predate the microVM-snapshot wave** — our angle is the recent systems work they don't cover | All incumbents are classics (Broder–Mitzenmacher 2002, Luo et al., 2021 domain survey) or broad-and-foundational ("Bloom Filters at Fifty," MDPI Dec 2025) — **none centers 2024–26** |
| Status right now | Day 4, Phase 1, **200 papers registered**, 8 commits, clean tree | Day 4, Phase 1, **168 papers registered**, 8 commits, clean tree |

Both are narrow, read-heavy survey papers — **no experiments** — written to be readable by an undergraduate systems/DSA audience. Target venue class (decided at Phase 4, by you): workshop / arXiv-first / IEEE Access class, with TMLR survey track as stretch.

---

## 2. What did we start with? (origin, Sun 2026-08-30 morning)

**What you brought:** You're an LPU student heading into Term 3 (CSE202, CSE205, CSE306, CSE307, CSE423, GEN231, INT335, MTH401 + LE basket), with priorities set: Term-3 prep, practical software-dev skills/projects, fitness. Your standing preferences: verified deliverables over plans, multi-source research with inline citations and honest limitations, community opinions checked for course-type questions, paper-notebook-style planning.

**What you asked for:** Recurring Hermes research loops that take you from literature collection to drafted publishable papers, on autopilot — the agent works daily, you review and edit.

**The evidence-first topic selection** (before anything was built, each niche got a seed scan):

- **Loop 1 scan:** 56 arXiv papers since 2024 matching `abs:"serverless" AND abs:"cold start"`, newest just days old, **0 arXiv surveys in that scope** → real gap. But we then checked beyond arXiv and honestly recorded **3 incumbent surveys** (ACM CSUR 2024 SLR — DOI 10.1145/3700875; Computing/Springer 2024; JSA 2024) → the angle shifted from "no surveys exist" to "the incumbents predate the 2024–26 infra wave."
- **Loop 2 scan:** ≥100 arXiv papers since 2024 in the AMQ space, **0 arXiv survey titles since 2024** (5 ever; newest 2021), top venues actively publishing 2025 parallel filters (Wormhole TPDS, PipeFilter TKDE), plus a genuinely fresh 2025 adversarial-robustness/DP thread. Incumbents exist but none covers the recent window.

**Decisions locked at the start:** autopilot mode (you gate Phase 4 framing + Phase 7 submission, everything else runs); cadences loop 1 daily 09:30 + Sunday 18:00, loop 2 daily 10:00 + Sunday 18:30 (offset so check-ins never collide); **citations fetched programmatically only** (arXiv API / Semantic Scholar / Crossref DOI) — never hand-typed; day counting via an explicit STATE.md field, never log lines.

---

## 3. What did we plan? (the scheme)

Each loop is a **7-phase pipeline**, defined in `ROADMAP.md`, advanced only by Sunday gate checks (exception: Phase-1 collection rounds can continue across days). One unit of work per tick, never more.

| Phase | What it is | Unit of work | Gate to advance |
|---|---|---|---|
| 0 Setup | workspace, git, roadmap | — | files exist ✔ (done Aug 30) |
| 1 Literature collection | breadth → depth | one round: 3–6 queries OR one citation snowball | ≥40 papers registered; incumbent check beyond arXiv done; ≥5 taxonomy-hint sentences in `notes/taxonomy.md` |
| 2 Taxonomy | structure the field | one branch defined + papers assigned | ≥4 top-level categories; every paper assigned or explicitly parked |
| 3 Deep reading | extract knowledge | one paper → `notes/papers/<id>.md` (problem/method/results/limitations/ONE quotable line) + programmatic BibTeX | ≥15 core papers noted, ≥15 verified bib entries, 3–5 gap sentences |
| 4 Framing + outline | **🔒 YOUR GATE** | title candidates / contribution sentence / section skeleton / venue comparison into `paper/outline.md` | you approve title + venue + scope in a reply |
| 5 Drafting | autopilot writing | one subsection, 200–400 words, every factual sentence cited or `[unverified]` | full draft assembled in `paper/draft.md` |
| 6 Simulated review | quality control | 3-reviewer ensemble (negative bias, structured) + meta-review, or one revision pass; every number traces to a note file | no open critical/high items |
| 7 Submission prep | **🔒 YOUR GATE** | LaTeX conversion, venue checklist, compile-fix loop, arXiv decision | submission-ready PDF + your explicit go |

Phase 1 also has a **stop condition**: when a round finds >80% of hits already collected, collecting ends. (Both loops just ran saturation probes — 29% and 22% overlap — so collecting continues.)

---

## 4. What is the way of approach? (the operating system)

**The workspace is the state machine.** No agent — cron tick, subagent, or a fresh chat — needs conversation history. Everything needed to continue lives in the repo:

- `STATE.md` — the single source of truth: phase, **explicit day counter**, next action (precisely scoped), cumulative stats, append-only log
- `ROADMAP.md` — the contract: phases, unit definitions, gates, incumbents, the angle, honest competitor watch
- `papers/candidates.md` — the register: every hit as `[id] year — title — relevance | S2 cites: N | status: collected/noted/parked`; dedupe by id with version-suffix normalization; **never delete entries, only change status**
- `AGENTS.md` (loop 1; loop 2's equivalent is embedded inline in its cron prompts) — the binding rules: read STATE first, do exactly ONE unit, never jump phases, update STATE before replying, commit every tick, append-only log, never fabricate, `[CITATION NEEDED]` over invention, retry once then log failures honestly, **never stall the loop on a pending user decision — execute the next unblocked unit**
- `notes/`, `paper/`, `scripts/`, `reviews/` — taxonomy hints, per-paper notes, draft sections, sweep/analysis scripts, Sunday retrospectives

**The daily rhythm** (intended): the 09:30/10:00 cron tick reads STATE → does one unit → updates STATE → commits → replies with a check-in:

```
⚡ Day N | Phase X — <what got done>
📊 papers: A | notes: B | words: C | streak: N days
▶ Tomorrow: <the single next unit>
❓ <optional: ONE decision, as numbered options>
```

**The honesty discipline** (this is what makes it a real research system): sweep JSONs and snowball JSONs are kept as artifacts on disk so every register entry traces to evidence; citation counts show "—" when S2 is rate-limited, never a guess; false-positive clusters (recommender-system "cold start", physics "survey" noise) are identified and excluded, not silently dropped; a seeded fact that turns out wrong (Filić was ASIACRYPT **2024**, not 2025) gets corrected in the register with the resolution recorded.

---

## 5. What actually happened (the full record)

**Sun Aug 30 — build day + infrastructure war:**
- Both workspaces built, git-initialized, cron pairs created. Loop-2's AGENTS.md write was consent-blocked twice (the tool even falsely reported success once — caught by a disk check), so loop 2's rules live inline in its cron prompts.
- The day's cron failures: 09:30 heartbeat hung on a non-streaming API call (watchdog killed it at 675s, zero work done); a **desktop-app relaunch at 10:48:21** killed four in-flight things at once; the re-fires then died on HTTP 429 (the free tier's shared **8-requests/minute cap** — my chat turns and both ticks draw from one pool) and a 90s API timeout.
- Resolution: **the never-stall rule was born** — both Day-1 units executed inline by me, same protocol and artifacts: loop 1 a 195-paper arXiv sweep → 56 registered; loop 2 a 209-paper sweep → 47 registered + incumbent check completed via web (S2 was 429-blocked) + Wormhole/PipeFilter DOI resolutions. Commits `c8949d4`, `a13f75c`.
- **18:00/18:30 — the two Sunday reviews ran via cron successfully** (still the only cron ticks that have ever worked). Both gates honestly blocked at 2/3: papers ✔, incumbent check ✔, `taxonomy.md` missing ❌. Fix plan: taxonomy hints in the week's dailies.

**Mon Aug 31 – Thu Sep 3 — every daily tick died; every unit ran anyway.** Four days, four failure classes (endpoint hangs up to 1018s, provider-unreachable at birth, the shared 429 pool, and one tick starving 660s behind a hung sibling on the workdir lock). After you said "run both inline," that became standing procedure — I check the tick's corpse, salvage any scripts it left on disk, execute the day's unit in my own streaming session, and record an honest attempt-log line in STATE.md.

The work itself, day by day:

- **Day 2 (Round 1B, both loops):** gate blocker cleared — 7 grounded taxonomy-hint sentences each. Loop 1: +35 pre-2024 depth papers, fixed a classifier bug ("LambdaMART" matched the token "lambda"), verified W35 leads, snowballed the CSUR incumbent → 102 registered. Loop 2: +59 pre-2024 classics with real S2 counts, **all 4 seeded placeholder DOIs resolved via Crossref** → 116. **All three gate conditions now met on both loops.**
- **Day 3 (Round 2):** loop 1 breadth — 4 new query angles → 72 more registered (SEUSS, "How Low Can You Go?", Cloudburst/Faasm stateful-warm line) → 174. Loop 2 — snowballs off the three central papers → 36 more (ZOR, Fingerprint, Adaptive Quotient, Aleph, PTHash, Tiny Pointers) → 153, plus 5 adjacent incumbent surveys added to the competitor watch — none centers 2024–26; angle holds.
- **Day 4 (today):** both saturation probes say **NOT saturated** (29% / 22% overlap ≪ 80%). Loop 1 found a brand-new vein — **systems-venue papers invisible to keyword search** (Fork-in-the-Road OSDI'25, Pronghorn, Sabre, PMem SnapStart, Deep-Freeze, Faasnap) → **200 registered**. Loop 2 added 11 net-new including two theory lower-bound papers → **168 registered**. Evening addendum: I found the root cause of the S2 null-citation mystery (the batch API needs `fields` as a query param, not body JSON — it silently returns 200-with-nulls otherwise) → **141 + 98 citation counts backfilled across both registers**, and loop 1's Wild-snowball retry surfaced **52 Round-4 seeds**.

**Scoreboard:** 16 commits total, both trees clean, 4-day streak on both loops, zero fabricated entries, every number traceable to a disk artifact.

---

## 6. How a new person or new LLM picks this up

Hand this section (plus the repo) to any fresh agent and the loops continue without me:

1. **Read, in order:** `STATE.md` (phase, day counter, next action — it's precisely scoped) → the current phase's section in `ROADMAP.md` (unit definition + gate) → loop-1's `AGENTS.md` (loop 2: rules are in the cron prompt itself) → the tail of `papers/candidates.md` (register format + dedupe rules).
2. **Do exactly ONE unit.** If it's too big, do part and write the remainder into `Next action`.
3. **Update STATE.md before replying** (log line, next action, stats, streak), then `git add -A && git commit -m "tick: ..."`. Never push, never rewrite history, append-only log.
4. **Register rules:** dedupe by id with version-suffix normalization (v2/v3 suffixes); statuses only change, entries never get deleted; non-arXiv papers go in as DOI/eprint prose entries.
5. **Citations programmatic-only.** arXiv API (no key, curl), S2 (beware 429s; `fields` is a *query* param), Crossref DOI negotiation. Unfetchable = `[CITATION NEEDED]`.
6. **Infra realities** (the hard-won part): the free model endpoint hangs on non-streaming calls → cron ticks die to a 600s watchdog; the 8-req/min cap is shared account-wide; the desktop app relaunches itself several times a day killing in-flight ticks; all 4 cron jobs share workdir locks and serialize. **Ground truth is never the wrapper's "outcome unknown" — it's `~/.hermes/cron/jobs.json` (fire_claims, PIDs, last_error), the session dumps, `git status`, and the disk.** The response to a dead tick: salvage its artifacts, execute inline, log honestly. The loop must never stall.
7. **You (Harsha) own:** Phase 4 framing (title/venue/scope — numbered options will be presented), Phase 7 submission, and any ❓ flagged in a check-in. Everything else is autopilot.

**Immediate next events:** Fri 09:30/10:00 daily ticks (the ongoing cron credibility test), **Sun Sep 6 18:00/18:30 — the Phase 1→2 gate confirmations** (all three conditions already met on both loops, so if the reviews run, both loops graduate to Taxonomy week). Open decisions still parked for you, no rush: tick staggering (I recommend leave-as-is) and the optional weekday "did the loops run?" watchdog.

---

Want me to save this as `HANDOFF.md` in each repo (committed, so any future tick or person literally has it on disk)?Both STATE files updated — Day counter 1, streak 1, complete unit records. Final verification sweep and commits for both repos:Both repos committed clean. Here's the double Day-1 check-in:

---

## ⚡ Day 1 | Phase 1 — both loops delivered their first real unit

**Loop 1 — cold-start survey (CSE423):**
📊 papers: 56 registered (25 collected / 21 noted / 10 parked) from a 195-paper arXiv sweep | streak: 1 day
- All planned branches populated: snapshot/restore (PhoenixOS, Aquifer), keep-alive (Green-or-Fast, Model Parking Tax), WASM (Epico, Lumos), predictive scheduling (MPC, transformer-based), LLM-serving cold start (vLLM analysis, Foundry, HydraServe)
- ~40 false positives (recommender-system "cold start" — a different field) identified and excluded

**Loop 2 — AMQ survey (CSE205×MTH401):**
📊 papers: 59 registered (32 collected / 24 noted / 3 parked) from a 209-paper sweep | S2 incumbent check: **completed** | streak: 1 day
- The 2024–26 window is real and populated: learned filters (7 papers), GPU/parallel hardware (6), adversarial-DP thread (7), cuckoo/sketch variants
- Incumbent verdict: **no survey centers the 2024–26 window** — classics + "Bloom Filters at Fifty" (MDPI, Dec 2025) are all broad/foundational. Angle holds.

▶ Tomorrow (both): Round 1B depth — pre-2024 classics registration + S2 citation counts (when 429s clear) + first taxonomy-hint sentences (Phase-1 gate item)

---

## ⚠️ The infrastructure saga (honest version)

Today's heartbeats didn't survive contact with the free endpoint, but the loops did:

1. **09:48** — loop 1's heartbeat died: 600s timeout waiting on a non-streaming API response
2. **10:48** — an app relaunch killed loop 2's mid-sweep tick (its sweep data survived on disk — that's why the resume worked)
3. **11:27–11:32** — both re-fires died too: HTTP 429 ("max 8 requests/minute" — my chat turns + both ticks share one free-tier pool) and another 90s API timeout
4. **Resolution** — per the loops' own never-stall rule, I executed both Day-1 units inline myself: same sweeps, same registers, same STATE updates, same commits. Everything above is real, committed work (`c8949d4`, `a13f75c`).

**What this means:** the endpoint is moody today (hangs + tight shared rate cap). The scheduled ticks tomorrow (09:30 / 10:00) may hit the same wall — if they do, the diagnosis + inline-rescue is now a fast, practiced move, and nothing is lost.

❓ **One decision for you:** given the 8-req/min shared cap, should I stagger tomorrow's two ticks further apart (e.g. 09:30 → 09:00 and 10:00 → 10:30) so they never collide with each other, or leave as-is since collisions with *your* chat usage are the real risk either way?
1. **Leave as-is** (recommended) — the inline-rescue pattern works; moving slots doesn't fix chat-usage collisions
2. **Stagger wider** — extra safety between the two ticks specifically
3. **Different time entirely** — tell me what works for your morningsLet me verify the current ground truth first (git, STATE files, cron jobs, current time) so this report states facts, not memories:Full accounting, verified against git logs, both STATE files, and live cron state just now. Time of writing: **Thursday 2026-09-03, 23:18 IST** — you last saw the Day-1 check-in on Sunday afternoon.

---

## The scheme (unchanged, now proven)

Two autonomous research loops, each a git workspace acting as a state machine — `STATE.md` (day counter, phase, next action, append-only log) + `ROADMAP.md` (phases 0–7 with Sunday gates) + a paper register (`papers/candidates.md`). Daily heartbeats do **exactly one unit** per tick; Sunday reviews check the phase gate. You hold the framing (Phase 4) and submission (Phase 7) gates; everything else runs on autopilot. Citations programmatic-only (arXiv API / S2 / Crossref DOI). The **never-stall rule** — if cron dies, execute the unit inline — ended up being the load-bearing part of the whole design, as you'll see.

## Timeline: what actually happened

**Sun Aug 30, evening — the Sunday reviews ran via cron successfully** (the only two cron ticks that have ever worked): loop 1 at 18:00, loop 2 at 18:30. Both gates **blocked at 2/3** — papers registered ✔, competing-survey check ✔, but `taxonomy.md` didn't exist yet ❌. Honest verdicts, retrospectives written (`reviews/2026-W35.md`, `reviews/2026-08-30.md`), fix plan: land taxonomy hints in the week's daily units. Loop-2's review also added an adjacent incumbent (ACM CSUR learned-index survey, Oct 2025) to the competitor watch and live-verified all 59 registrations.

**Mon Aug 31 – Thu Sep 3 — every single daily cron tick died; every single unit ran anyway.** Four days, four failure classes, zero lost work:

| Day | Loop 1 (09:30 slot) | Loop 2 (10:00 slot) | What I did |
|---|---|---|---|
| Mon 31 | heartbeat hung 1018s on the endpoint; auto-refire died ~30 min in mid-unit | re-fire: provider unreachable, then **660s TERMINAL_CWD lock** starved behind the hung loop-1 tick (the workdir-serialization hazard, now confirmed live) | You directed "run both inline"; salvaged the dead tick's scripts off disk, started Round 1B |
| Tue Sep 1 | — (Day-2 unit completing) | — | Finished Round 1B for both (overnight pause) |
| Wed Sep 2 | watchdog timeout, same class | "can't reach the model provider" | Both Day-3 units executed inline same day |
| Thu Sep 3 | 09:30 hang + 15:59 catch-up died (150s timeout — **failure streak now 7**) | died at birth (streak 5); a 16:15 catch-up ran 9 min, left a reconcile script, died | Both Day-4 units + S2 backfill addendum executed inline; ran and verified the dead tick's salvage script |

By end of Day 2, "re-fire and pray" was abandoned — inline execution became the standing operating mode, per your call. Cron gets its next natural test tomorrow 09:30/10:00 and the Sunday gates on Sep 6.

## What was achieved (content, day by day)

**Loop 1 — serverless cold-start survey (CSE423)** — register: **56 → 200 papers**, 8 commits, streak 4:
- **Day 2 (Round 1B)**: gate blocker cleared — `taxonomy.md` with 7 grounded hint sentences. Pre-2024 depth (+35), incl. fixing a classifier bug where "LambdaMART" matched the token "lambda" (recommender false-positives slipped in). W35 leads verified; CSUR-incumbent snowball → 5 registered. **All 3 gate conditions now met.**
- **Day 3 (Round 2 breadth)**: 4 new query angles → 109 new papers, 72 registered (SEUSS, "How Low Can You Go?", the Cloudburst/Faasm stateful-warm line, WASM branch filled). Overlap 44% — below the 80% stop condition.
- **Day 4 (Round 3 saturation probe)**: venue-targeted sweep found a **brand-new vein** — systems-venue papers invisible to keyword search (Fork-in-the-Road OSDI'25, Pronghorn, Sabre, PMem SnapStart, Deep-Freeze, Faasnap...). Probe verdict: **29% overlap — NOT saturated**, loop continues into Round 4.
- **Day 4 addendum (~22:50 tonight)**: found and fixed the S2 silent-failure root cause (the batch API needs `fields` as a query param, not body JSON — it returns HTTP 200 with all-nulls otherwise) → **141 citation counts backfilled** (ServerlessLLM 188, FaaSNet 169, Remote-Fork 93...); Wild snowball retried → 927 citers → **52 Round-4 seeds reserved**.

**Loop 2 — AMQ/probabilistic-DS survey (CSE205×MTH401)** — register: **59 → 168 papers**, 8 commits, streak 4:
- **Day 2 (Round 1B)**: taxonomy blocker cleared; 59 pre-2024 classics registered with citation counts; **all 4 seeded placeholder DOIs resolved via Crossref** (Parallel Wormhole = TPDS, PipeFilter = TKDE, Lotan&Naor = IACR CiC, Filić = LNCS).
- **Day 3 (Round 2)**: snowballs off the three central papers → 36 registered (ZOR, Fingerprint, Adaptive Quotient, Aleph, PTHash, Tiny Pointers...). **Caught and fixed a seeding error**: Filić is ASIACRYPT **2024**, not 2025. 5 adjacent incumbent surveys registered — none centers the 2024–26 window; angle still holds.
- **Day 4 (Round 3 probe)**: 22% overlap — NOT saturated; 11 net-new incl. two **theory lower-bound papers** (dynamic-AMQ, space) — a lineage line the roadmap didn't anticipate. Fixed a register gap (2021 BF Survey incumbent was in ROADMAP but never in candidates.md).
- **Day 4 addendum (tonight)**: same S2 fix → **98 counts backfilled** (How-to-Approximate-a-Set 215, sandwiching-LBF 214, PTHash 56...).

## Where both loops stand right now

Both at **Day 4, Phase 1, streak 4, all gate conditions met, saturation NOT reached** — so the collecting continues into Round 4 (tomorrow's units: loop 1 mines the venue vein + triages the 52 Wild-snowball citers; loop 2 snowballs the next centrality tier + the theory lineage). First confirmation gates: **Sunday Sep 6, 18:00/18:30** — if they hold, both loops move to Phase 2 (reading + note-taking at scale).

## Open items (no action needed tonight)

1. **Cron credibility**: 0-for-8 on daily ticks since Aug 31 — all failure-streak counters climbing, but nothing auto-disables. Tomorrow's ticks are the next test; inline rescue is a practiced ~1-hour move now.
2. Your two unanswered questions from Sunday: tick staggering (left as-is) and the optional "did the loops run?" watchdog offer — both still open, both non-blocking.
3. Small honesty debts recorded in STATE: a handful of S2-count stragglers (23 ids loop 1, 5 ids loop 2) queued for quiet-minute retries; never marked as anything but "—".