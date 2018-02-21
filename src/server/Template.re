let make = (~content, ~title, ~meta, ~link, ~script, ~htmlAttr, ~app_bundle, ~vendor_bundle, ~loadableScript, ()) => {j|
    <!DOCTYPE html>
      <html $htmlAttr>
        <head>
          $title
          $meta
          $link
          $script
        </head>
        <body>
          <div id="root">$content</div>
          $loadableScript
          <script src="/$(vendor_bundle)" defer></script>
          <script src="/$(app_bundle)" defer></script>
        </body>
      </html>
  |j};