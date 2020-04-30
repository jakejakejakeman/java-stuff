package edu.ufl.cise.cs1.controllers;

import game.controllers.AttackerController;
import game.models.Defender;
import game.models.Game;
import game.models.Node;

import java.util.List;

public final class StudentAttackerController implements AttackerController
{
	public void init(Game game) { }

	public void shutdown(Game game) { }

	public int update(Game game,long timeDue)
	{
		//Chooses a random LEGAL action if required.
		List<Node> nay = game.getPillList();
		List<Defender> guys = game.getDefenders();
		Node dad = game.getCurMaze().getInitialDefendersPosition();
		for (int i=0;i<nay.size();i++)
			if (game.getAttacker().getLocation().getPathDistance(nay.get(i))<game.getAttacker().getLocation().getPathDistance(dad))
				dad=nay.get(i);
		// This section of code starts my program choice mechanism to decide what actions to take given the game circumstances
		int action=game.getAttacker().getNextDir(dad,true);
		game.models.Actor bad = game.getAttacker().getTargetActor(guys, true);
		int fear = game.getAttacker().getLocation().getPathDistance(bad.getLocation());
		if ((game.checkPowerPill(game.getAttacker().getLocation().getNeighbor(action)))&&(!((fear<9)&&(fear>0))))
			action=game.getAttacker().getReverse();
		else if (game.getDefender(0).isVulnerable())
			action=game.getAttacker().getNextDir(game.getDefender(0).getLocation(),true);
		else if (game.getDefender(1).isVulnerable())
			action=game.getAttacker().getNextDir(game.getDefender(1).getLocation(),true);
		else if (game.getDefender(2).isVulnerable())
			action=game.getAttacker().getNextDir(game.getDefender(2).getLocation(),true);
		else if ((fear<9)&&(fear>0))
			action=game.getAttacker().getNextDir(bad.getLocation(), false);
		else
			action = game.getAttacker().getNextDir(dad,true);
		return action;
	}
}