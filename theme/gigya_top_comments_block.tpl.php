<div class="gigya-top-comments">
<?php
  print '<ul id="gigya-top-comments">';
  $i = 0;
  $length = count($query_content);
  
  if (!empty($query_content)){
    foreach ($query_content as $stream) {
      $node_content = node_load($stream->sid);
      if ($node_content) {
        $node_title = $node_content->title;
        $node_path = 'node/' . $stream->sid;
        print '<li class="top_content_item">';
        print '<span class="comment_count">' . l($stream->comment_count, $node_path) . '</span>';
        print '<div class="meta"><span class="node_title">' . l($node_title, $node_path) . '</span>';
      }
      else {
        print '<li class="top_content_item">';
        print '<div class="meta"><span class="node_title">Content not found. Stream ID ' . $stream->sid . ' does not match any node ID\'s.</span>'; 
      }
      if ($i == $length - 1) {
        print '</div></li>';
      }
      else {
        print '</div></li><hr class="gigya_top_comments_item_divider" />';
      }
      $i++;
    }
    print '</ul>';
  }
?>
</div>