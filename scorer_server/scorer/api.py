from flask import Blueprint, abort, jsonify
from flask import current_app as app

from scorer.db.update import add_team, add_attack
from scorer.manager import get_attack_manager, get_team_manager

bp = Blueprint('api', __name__)


@bp.route('/team/<team_name>')
def team_update(team_name):
    app.logger.debug(f"Code update for team: '{team_name}'")
    team = get_team_manager().process_team(team_name)
    if not team:  # If the team was invalid.
        abort(400)

    add_team(team.id)
    return jsonify(id=team.id)


@bp.route('/attack/<attack_name>')
def new_attack(attack_name):
    app.logger.debug(f"New Attack submitted: '{attack_name}'")
    attack = get_attack_manager().process_attack(attack_name)
    if not attack:  # If the attack was invalid.
        abort(400)

    add_attack(attack.id)
    return jsonify(id=attack.id)
