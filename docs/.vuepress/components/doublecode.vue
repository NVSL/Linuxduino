<template>
  <div>
    <slot name="js"></slot>
    <slot name="c"></slot>
  </div>
</template>

<script>

export default {
  name: 'doublecode',
  props: {
    // w: Number,
    // h: Number,
    // brightness: String,
    // color: String
  }, 
  data() {
    return {
    }
  },
  mounted: function () {
  },
  methods: {
  }
}
</script>

<style>
  
</style>