<section class="owstech-share">

  <h3 class='actuator'><a title="Share"><?php print $owstech_share_actuator_text; ?></a></h3>

    <ul class="drawer">

      <!-- @todo, these li's could possibly be turned into a forloop based on the checkbox values from the menu forms -->
      <?php if( $owstech_share_include_facebook ): ?>
      <li>
        <a class="icon facebook" rel="nofollow" title="<?php print $share_cta_fb; ?>" target="_blank" href="<?php print $share_url_fb; ?> ">
          <span><?php print $share_cta_fb; ?></span>
        </a>
      </li>
      <?php endif; ?>

      <?php if( $owstech_share_include_twitter ): ?>
      <li>
        <a class="icon twitter" rel="nofollow" title="<?php print $share_cta_twitter; ?>" target="_blank" href="<?php print $share_url_twitter; ?>">
          <span><?php print $share_cta_twitter; ?></span>
        </a>
      </li>
      <?php endif; ?>

      <?php if( $owstech_share_include_googleplus ): ?>
      <li>
        <a class="icon google-plus" rel="nofollow" title="<?php print $share_cta_googleplus; ?>" target="_blank" href="<?php print $share_url_googleplus; ?>">
          <span><?php print $share_cta_googleplus; ?></span>
        </a>
      </li>
      <?php endif;?>

      <?php if( $owstech_share_include_reddit ): ?>
      <li>
        <a class="icon reddit" rel="nofollow" title="<?php print $share_cta_reddit;?>" target="_blank" href="<?php print $share_url_reddit;?>">
          <span><?php print $share_cta_reddit; ?></span>
        </a>
      </li>
      <?php endif; ?>

    </ul>

</section>
