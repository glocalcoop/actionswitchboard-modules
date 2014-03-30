<?php
/**
 * @file
 * asb_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function asb_features_default_rules_configuration() {
  $items = array();
  $items['og_og_member_approved'] = entity_import('rules_config', '{ "og_og_member_approved" : {
      "LABEL" : "OG member approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_approved" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
        { "AND" : [
            { "NOT og_user_has_permission" : {
                "permission" : "administer group",
                "group" : [ "og-membership:group" ],
                "account" : [ "account" ]
              }
            }
          ]
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
            "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
          }
        },
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Your membership request was approved for \\u0027[group:title]\\u0027\\r\\n",
            "message" : "[account:name],\\r\\n\\r\\nYour membership in the scheme \\u0027[group:title]\\u0027 has been approved by the scheme leader. Go ahead and join in the plotting with the rest of the band of schemers at [group:url]!\\r\\n\\r\\nThe Action Switchboard Team",
            "language" : [ "" ]
          }
        },
        { "og_grant_og_role" : {
            "account" : [ "account" ],
            "group" : [ "group" ],
            "roles" : { "value" : { "Schemer" : "Schemer" } }
          }
        }
      ]
    }
  }');
  $items['rules_authenticated_to_schemer'] = entity_import('rules_config', '{ "rules_authenticated_to_schemer" : {
      "LABEL" : "Authenticated to Schemer",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "user" ],
      "REQUIRES" : [ "rules", "privatemsg_rules", "logintoboggan_rules" ],
      "ON" : { "logintoboggan_validated" : [] },
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } },
        { "privatemsg_rules_new" : {
            "USING" : {
              "recipient" : [ "account" ],
              "author" : "90",
              "subject" : "Welcome to the Action Switchboard!",
              "body" : "Hi [account:name],\\r\\n\\r\\nThanks for registering with the Action Switchboard as a beta tester! The Action Switchboard team, the whole Yes Lab and I think you\\u0027ll enjoy using it. Go ahead and poke around the site, search for schemes or create some of your own. If you notice any bugs or want to make a suggestion to us, there\\u0027s a special link to a form for beta testers at the bottom of every page.\\r\\n\\r\\nSome features are not yet functional, but we are working hard on them. Once we go live, you\\u0027ll be able to publicize your scheme by sharing its link on the Internet. In the meantime, your scheme pages will be hidden from the general public.\\r\\n\\r\\nFor now, please use the Action Switchboard to plot and plan with your fellow schemers. If you start your own scheme, you\\u0027ll also see a button on your scheme to contact your Yes Lab facilitator if you need advice, collaborators, or help with your planning. Take the next few weeks to get your scheme\\u0027s public content ready for showtime, and you\\u0027ll be all set once the Action Switchboard goes live. (And if you\\u0027ve already accomplished your action by then, we can post it as a completed scheme!)\\r\\n\\r\\nYour partner in mischief,\\r\\nAndy"
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        }
      ]
    }
  }');
  $items['rules_follow_scheme'] = entity_import('rules_config', '{ "rules_follow_scheme" : {
      "LABEL" : "Follow Scheme",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "scheme" ],
      "REQUIRES" : [ "flag" ],
      "ON" : { "flag_flagged_subscribe_og" : [] },
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "email_og",
            "node" : [ "flagged-node" ],
            "flagging_user" : [ "flagging_user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_rule_component_for_sending_reminders'] = entity_import('rules_config', '{ "rules_rule_component_for_sending_reminders" : {
      "LABEL" : "Rule component for sending reminders",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workflow_rules" ],
      "USES VARIABLES" : { "rule_conf" : { "label" : "Rules Configuration", "type" : "rules_config" } },
      "IF" : [
        { "workflow_check_state" : {
            "node" : [ "site:og-context--node" ],
            "workflow_state" : { "value" : { "2" : "2" } }
          }
        }
      ],
      "DO" : []
    }
  }');
  $items['rules_scheme_approved'] = entity_import('rules_config', '{ "rules_scheme_approved" : {
      "LABEL" : "Scheme Approved",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workflow_rules", "rules", "mimemail", "og" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "scheme_approved",
            "to" : [ "node:author:mail" ],
            "reply_to" : "noreply@actionswitchboard.net",
            "subject" : "Your scheme has been approved!!!",
            "body" : "Hi [node:author],\\r\\n\\r\\nCongratulations! \\r\\n\\u003Cp\\u003EYour scheme [node:title] has been approved, and can be found at [node:url]. Your facilitator will be sending it around to folks they think might want to help out. \\u003C\\/p\\u003E\\r\\n\\r\\nHere\\u0027s what you should do next:\\r\\n\\r\\n\\u003Cli\\u003EBuild your team by adding members to your scheme\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EInvite friends you want to scheme with to join the Action Switchboard to get started. Send them the link to your scheme and they can request membership there.\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EKeep an eye on your dashboard (and email) for messages from interested schemers.\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EPromote your scheme on Facebook, Twitter, or your blog. Make sure to use the hashtag #schemers so we can see you on twitter. (And follow us @ActionSwitchBrd)\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EOnce your team has been assembled, you\\u2019ll be able to use the Action Switchboard toolkit for all of your plotting and planning.\\u003C\\/li\\u003E\\r\\n\\u003Cp\\u003EAbove all\\u2013start! You don\\u2019t have to wait to begin making your scheme a reality. See our Cookbook on the Action Switchboard for tips and how-tos.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThe Action Switchboard Team\\u003C\\/p\\u003E",
            "plaintext" : "Hi [node:author],\\r\\n\\r\\nCongratulations! \\r\\nYour scheme [node:title] has been approved, and can be found at [node:url]. Your facilitator will be sending it around to folks they think might want to help out. \\r\\n\\r\\nHere\\u0027s what you should do next:\\r\\n\\r\\nBuild your team by adding members to your scheme\\r\\nInvite friends you want to scheme with to join the Action Switchboard to get started. Send them the link to your scheme and they can request membership there. \\r\\nKeep an eye on your dashboard (and email) for messages from interested schemers. \\r\\nPromote your scheme on Facebook, Twitter, or your blog. Make sure to use the hashtag #schemers so we can see you on twitter. (And follow us @ActionSwitchBrd)\\r\\nOnce your team has been assembled, you\\u2019ll be able to use the Action Switchboard toolkit for all of your plotting and planning.\\r\\n\\r\\n\\r\\nAbove all\\u2013start! You don\\u2019t have to wait to begin making your scheme a reality. See our Cookbook on the Action Switchboard for tips and how-tos.\\r\\n\\r\\nThe Action Switchboard Team",
            "language" : [ "" ]
          }
        },
        { "user_add_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "5" : "5" } } } },
        { "og_grant_og_role" : {
            "account" : [ "node:author" ],
            "group" : [ "node" ],
            "roles" : { "value" : { "Scheme Leader" : "Scheme Leader" } }
          }
        }
      ]
    }
  }');
  $items['rules_scheme_rejected'] = entity_import('rules_config', '{ "rules_scheme_rejected" : {
      "LABEL" : "Scheme Rejected",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "Sorry, but your scheme was not approved.",
            "message" : "Hello [node:author],\\r\\n\\r\\nYour scheme [node:title] has been rejected by the Action Switchboard Team.  We hope you will continue to come up with interesting ideas, but this time, something didn\\u0027t work about what you suggested for your scheme.  We\\u0027d like to see you back again.  So look over the schemes at [site:url] and grab some inspiration!\\r\\n\\r\\nSincerely,\\r\\n\\r\\nThe Action Switchboard Team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_scheme_updated'] = entity_import('rules_config', '{ "rules_scheme_updated" : {
      "LABEL" : "Scheme Updated",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "scheme" ],
      "REQUIRES" : [ "workflow_rules", "asb_scheme", "rules" ],
      "ON" : { "node_update--scheme" : { "bundle" : "scheme" } },
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [ { "asb_scheme_create_civi_scheme_action" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_unfollow_scheme'] = entity_import('rules_config', '{ "rules_unfollow_scheme" : {
      "LABEL" : "Unfollow Scheme",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "scheme" ],
      "REQUIRES" : [ "flag" ],
      "ON" : { "flag_unflagged_subscribe_og" : [] },
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "email_og",
            "node" : [ "flagged-node" ],
            "flagging_user" : [ "flagging_user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
