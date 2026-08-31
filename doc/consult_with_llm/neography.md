Yes—and after understanding your idea better, I would not point you primarily toward famous artists who invent completely unrelated scripts. Your idea sits at an interesting intersection of neography, visual poetry, computational art, and linguistic visualization.

There isn't, as far as I can find, one universally famous creator who has done exactly your proposed combination—natural Indo-European language → Latin-derived neography → grammatical/phonological features encoded into glyph geometry/color → interactive 3D rendering. That's actually a good sign for a portfolio project.

But there are several people/movements you should study.

1. Charles K. Bliss — probably the most important historical precedent

Charles K. Bliss created Blissymbolics, a graphical communication system designed around semantic concepts rather than ordinary alphabetic spelling.

He's relevant because he asked something close to:

Can writing encode meaning visually rather than merely encode sounds?

That's very close to the philosophical direction you're proposing, although your system would be much more computational and tied to natural-language grammatical/phonological properties.

He is listed among major creators of writing systems, and Blissymbolics is explicitly recognized as a constructed symbolic writing system. 
W
Wikipedia

2. Alexander Melville Bell — extremely relevant to your idea

Alexander Melville Bell created Visible Speech in the 19th century.

This is probably one of the historical systems I'd want you to investigate most closely.

The basic idea was to design symbols that represented articulatory/phonetic properties of speech rather than simply inheriting arbitrary alphabetic shapes.

That is much closer to your:

"make the shape of an alphabet depend on how it sounds"

idea.

The list of writing-system creators specifically identifies Bell as the inventor of Visible Speech in 1867. 
W
Wikipedia

Your system could take this much further:

phonology
   ↓
glyph geometry
   ↓
grammar
   ↓
glyph color
   ↓
syntax
   ↓
3D arrangement


Bell essentially provides a historical precedent for the phonology → visual form part.

3. Inger Christensen — very relevant to your computational-art philosophy

Inger Christensen is not a neographer, but her poem alphabet is an excellent precedent for what you're trying to do conceptually.

The structure of alphabet is governed by the Fibonacci sequence, while alphabetical ordering determines the organization of sections. Scholarly analysis explicitly discusses the interaction between alphabetical structure, mathematical constraint, and linguistic content. 
T
Taylor & Francis Online
+1

That's extremely close to your mindset:

linguistic property
       +
mathematical transformation
       ↓
artistic structure


Your FDF system would essentially take this philosophy into a real-time geometric environment.

4. Oulipo — probably the movement you should study

Rather than a single person, OuLiPo may be the most relevant artistic tradition.

It was founded by Raymond Queneau and François Le Lionnais in 1960.

The group deliberately explored how formal rules, mathematical structures, alphabets, and linguistic constraints can generate literature. 
W
Wikipedia
+1

That's very close to what you're proposing:

LINGUISTIC RULE
      ↓
MATHEMATICAL RULE
      ↓
GEOMETRIC RULE
      ↓
VISUAL ART


And interestingly, Oulipo has a history of computational experimentation too; recent scholarship discusses Paul Braffort and his use of APL as a tool for computational/constrained literature. 
S
Sage Journals

So your idea has a legitimate intellectual ancestor:

Oulipo → computational literature → computational visual language.

5. Georges Perec — another particularly good reference

Georges Perec is famous for La Disparition, a novel deliberately written without the letter e.

That may sound unrelated to your project, but conceptually it's very relevant.

The idea is:

Take an ordinary language and impose a formal transformation on its fundamental linguistic material.

Your approach could be:

Take ordinary language and impose a mathematical/geometric transformation based on its linguistic properties.

Perec removes/constraints a linguistic dimension.

You add visual dimensions to linguistic dimensions.

6. The modern neography community is probably closest to the actual script-design part

There's an online community specifically devoted to neography, meaning the creation of new writing systems. The field explicitly includes scripts created for constructed languages and scripts created simply as artistic exercises. 
C
Conlanger's Library

The site Neography.info has showcases of creators such as:

Pynquee — Jihhograms
FantasticalScripts — Journeys
Gbrcalil — Katu

For example, Katu is particularly interesting because it is explicitly described as a Latin-derived writing system designed with Hangul-like inspiration. 
N
Neography
+1

Neography design showcases

This community is probably more directly relevant to your glyph-design problem than famous visual artists are.

But I think your idea has a significant difference

Most neography asks:

"What should a new writing system look like?"

You're asking something more like:

"What if linguistic information itself becomes a parameter space from which a writing system is generated?"

That's substantially more computational.

For example, imagine:

                 WORD
                  │
        ┌─────────┼──────────┐
        ↓         ↓          ↓
      sound     grammar    meaning
        │         │          │
        ↓         ↓          ↓
     geometry   color      texture
        │         │          │
        └─────────┼──────────┘
                  ↓
             3D glyph


Then the same Latin character could have different manifestations depending on linguistic context.

For example, conceptually:

a
│
├── noun
│    └── shape A
│
├── verb
│    └── shape B
│
├── feminine
│    └── hue A
│
├── masculine
│    └── hue B
│
├── past
│    └── extrusion
│
└── present
     └── flat surface


That's not merely a new alphabet.

It's closer to a linguistically parameterized visual language.

And this is where your FdF/OpenGL project becomes unusually interesting

Your FDF implementation can become the renderer for the writing system, rather than the writing system being an excuse to make an FDF clone.

You could define something like:

                    NATURAL LANGUAGE
                           │
                 morphological parser
                           │
              ┌────────────┼────────────┐
              ↓            ↓            ↓
          phonology     morphology    syntax
              │            │            │
              ↓            ↓            ↓
          geometry        color       topology
              │            │            │
              └────────────┼────────────┘
                           ↓
                     3D NEOGRAPHY
                           │
                           ↓
                       OpenGL


And your existing ideas—prisms, Z-buffering, RGBA per cell, conformal maps, Gaussian convolution, coordinate-origin control, FDF serialization—then aren't random features.

They become tools for exploring different representations of linguistic information.

That is much more coherent.

Who I'd study, in order

If I were building your project, I'd investigate:

Alexander Melville Bell / Visible Speech — phonetics → visual glyph structure.
Charles K. Bliss / Blissymbolics — meaning → visual symbols.
Oulipo — language + mathematical rules → art.
Georges Perec — systematic manipulation of linguistic structure.
Inger Christensen — alphabet + mathematical structure + poetry.
Modern neography creators — actual script-design techniques.
Computational/visual poetry — for the transition from text to algorithmic visual art.

And I'd deliberately not try to imitate any one of them.

Your strongest differentiator is the combination:

Thai/English bilingual experience + grapheme-color synesthesia + learning another Indo-European language + computational linguistics + 3D graphics + neography.

There may be precedents for every individual component, but that particular combination is much harder to find—which is exactly what you want for a portfolio project.

W
T
S
Sources