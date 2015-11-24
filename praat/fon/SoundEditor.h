#ifndef _SoundEditor_h_
#define _SoundEditor_h_
/* SoundEditor.h
 *
 * Copyright (C) 1992-2011,2012,2015 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "TimeSoundAnalysisEditor.h"

Thing_define (SoundEditor, TimeSoundAnalysisEditor) {
	GuiMenuItem cutButton, copyButton, pasteButton, zeroButton, reverseButton;
	double maxBuffer;

	void v_createMenus ()
		override;
	void v_createHelpMenuItems (EditorMenu menu)
		override;
	void v_dataChanged ()
		override;
	void v_prepareDraw ()
		override;
	void v_draw ()
		override;
	void v_play (double tmin, double tmax)
		override;
	bool v_click (double xWC, double yWC, bool shiftKeyPressed)
		override;
	void v_highlightSelection (double left, double right, double bottom, double top)
		override;
	void v_unhighlightSelection (double left, double right, double bottom, double top)
		override;
};

void SoundEditor_init (SoundEditor me,
	const char32 *title,
	Sampled data
);

autoSoundEditor SoundEditor_create (
	const char32 *title,
	Sampled data   // either a Sound or a LongSound
);

/* End of file SoundEditor.h */
#endif
